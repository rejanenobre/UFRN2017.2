#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
    /** @brief timeId eh uma variavel que armazena o Id de uma
      * cronometro utilizado na producao de dados**/
    int timeId =0;

    /** @brief IP eh uma variavel que armazena o IP da maquina utilizada.**/
    QString IP;

    /** @brief dados eh um vetor que armazena os dados coletados.
     *  @brief times eh um vetor que armazena os tempos respectivos dos dados coletados.**/
    vector<double> times, dados;

public:
  /** @brief MainWindow() eh o costrutor da classe de mesmo nome. Eh utilizada para a criacao
    * e manutencao de uma tela de exibicao.
    * @param *parent eh um ponteiro para a interface.**/
  explicit MainWindow(QWidget *parent = 0);

  /** @brief ~MainWindow() eh o destrutor da classe MainWindow()**/
  ~MainWindow();

  /** @brief timerEvent() eh requerido toda vez que houver o encerramento de um ciclo
    * do cronometro corrente
    * @param Sua entrada eh um ponteiro para um evento de tempo, a finalizacao do ciclo do cronometro.**/
 void timerEvent(QTimerEvent *);

public slots:

  /** @brief mudaIP() eh requerido toda vez que houver a alteracao do endereco de IP da maquina
    * utilizada.
    * @param _IP eh uma string que indica o IP da maquina utilizada.**/
  void mudaIP(QString _IP);

  /** @brief tcpConnect() eh utilizado para realizar a coneccao com o sistema. Se o IP de uma maquina
    * nao for fornecido, o IP utilizado serah "127.0.0.1".**/
  void tcpConnect();

  /** @brief tcpDesconnect() eh utilizado para realizar a desconeccao com o sistema.**/
  void tcpDesconnect();

  /** @brief Update() eh um slot que nos permite retornar a lista de IP das maquinas
    * que estao produzindo dados e apresenta-as com a ajuda da listWidget**/
  void Update();

  /** @brief getData() eh utilizado para realizar a coleta e manutencao de dados do sistema.**/
  void getData();

  /** @brief startTime() eh utilizado para realizar a inicializacao de um cronometro sempre que
    * desejemos comecar a producao de dados ou mudar o tempo de producao de dados.**/
  int startTime();

  /** @brief stopTime() eh utilizado para realizar a finalizacao do cronometro corrente
   * sempre que desejemos encerrar a producao de dados**/
  void stopTime();

  /** @brief changeTime() eh utilizado para realizar a modificacao do cronometro
    * durante a processamento de dados.**/
  void changeTime();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
