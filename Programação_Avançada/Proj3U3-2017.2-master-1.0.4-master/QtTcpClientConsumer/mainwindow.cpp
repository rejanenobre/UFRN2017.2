#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonConnect,
        SIGNAL(clicked(bool)),
        this,
        SLOT(tcpConnect()));

  connect(ui->pushButtonDisconnect,
        SIGNAL(clicked(bool)),
        this,
        SLOT(tcpDesconnect()));

  connect(ui->pushButtonUpdate,
          SIGNAL(clicked(bool)),
          this,
          SLOT(Update()));

  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(startTime()));

  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopTime()));
}

void MainWindow::mudaIP(QString _IP)
{
    IP = _IP;
}

void MainWindow::tcpConnect()
{
  if(IP == "") IP = "127.0.0.1";
  qDebug() << IP;

  socket->connectToHost(IP,1234);

  if(socket->waitForConnected(3000))  qDebug() << "Connected";
  else    qDebug() << "Disconnected";
}

void MainWindow::tcpDesconnect()
{
    socket->disconnectFromHost();

    if(socket->waitForConnected(3000))  qDebug() << "Connected";
    else    qDebug() << "Disconnected";

    killTimer(timeId);
}

void MainWindow::Update()
{
    QString str;
    QString list;
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
      if(socket->isOpen())
      {
        socket->write("list");
        socket->waitForBytesWritten();
        socket->waitForReadyRead();
        qDebug() << socket->bytesAvailable();

        while(socket->bytesAvailable())
        {
          str = socket->readLine().replace("\n","").replace("\r","");
          ui->listWidget->addItem(str);
        }
      }
    }
}

void MainWindow::getData()
{
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  QString date;
  qDebug() << "to get data...";

  if(socket->state() == QAbstractSocket::ConnectedState)
  {
    if(socket->isOpen())
    {
      times.clear();
      dados.clear();

      qDebug() << "reading...";
      date = "get " + IP + " 30\r\n";
      //converte QString -> String -> constString
      socket->write(date.toStdString().c_str());
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      qDebug() << "escreve";

      while(socket->bytesAvailable())
      {
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2)
        {
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          qDebug() << thetime << ": " << str;

          times.push_back(thetime);
          dados.push_back(str.toDouble(&ok));
        }
      }
      ui-> widget -> carregaDados(times,dados);
    }
  }
}

int MainWindow::startTime()
{
    int timing;
    if (timeId != 0) killTimer(timeId);
    timing = ui -> horizontalSliderTiming->value()*1000;
    timeId = startTimer(timing);
}

void MainWindow::stopTime()
{
    killTimer(timeId);
    timeId = 0;
}

void MainWindow::changeTime()
{
    if (timeId != 0)
    {
        int timing;
        killTimer(timeId);
        timing = ui -> horizontalSliderTiming->value()*1000;
        timeId = startTimer(timing);
    }
}

void MainWindow::timerEvent(QTimerEvent *)
{
    getData();
    qDebug() << "\n\n\nO getData foi...";
    ui -> widget -> repaint();
    qDebug() << "O repaint tambehm...\n\n\n";
}

MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
