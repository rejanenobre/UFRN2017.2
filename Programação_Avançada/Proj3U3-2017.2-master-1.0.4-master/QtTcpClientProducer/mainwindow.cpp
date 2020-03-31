#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow)
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

  connect(ui->pushButtonStart,
        SIGNAL(clicked(bool)),
        this,
        SLOT(startTime()));

  connect(ui->pushButtonStop,
        SIGNAL(clicked(bool)),
        this,
        SLOT(stopTime()));
}

void MainWindow::tcpConnect()
{
   if(IP == "") IP = "127.0.0.1";
   qDebug() << IP;

  socket->connectToHost(IP,1234);

  if(socket->waitForConnected(3000))    qDebug() << "Connected";
  else  qDebug() << "Disconnected";
}

void MainWindow::tcpDesconnect()
{
    socket->disconnectFromHost();

    if(socket->waitForConnected(3000))  qDebug() << "Connected";
    else    qDebug() << "Disconnected";

    killTimer(timeId);
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

void MainWindow::putData()
{
    QDateTime datetime;
    QString str;
    qint64 msecdate;

    if(socket->state()== QAbstractSocket::ConnectedState)
    {
        //Definição e ajuste de minimo e maximo:
        int max, min;
        max = ui-> horizontalSliderMax ->value();
        min = ui-> horizontalSliderMin ->value();


        if (max <= min)
        {
            if(max == 0)
            {
                max = max+1;
                qDebug() <<"Cuidado! O Max não pode ser zero! Modifique!\n\n";
            }
            if(min >= max)
            {
                min = max - 1;
                qDebug() <<"Cuidado! O Max <= Min! Modifique!\n\n";
            }
        }

        qDebug() << "max" << max;
        qDebug() << "min" << min;

        //Produção do dado:
        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();

        str = "set " + QString::number(msecdate) + " " +
        QString::number((qrand()%(max-min)) +min )+"\r\n\n";

        //Impressão do dado:
        qDebug() << str;
        ui->textBrowserDate->insertPlainText(str);

        qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
        if(socket->waitForBytesWritten(3000))   qDebug() << "wrote";
    }
}

void MainWindow::timerEvent(QTimerEvent *)
{
    putData();
}

void MainWindow::mudaIP(QString _IP)
{
    IP = _IP;
}

MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
