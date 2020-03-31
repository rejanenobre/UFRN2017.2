#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

using namespace std;

class Plotter : public QWidget
{
  Q_OBJECT
private:
protected:
    vector<double> times, dados;
public:
  /** @brief Plotter() eh utilizado para realizar a apresentacao de uma area de deseho.
    * @param QWidget *parent eh recebe o enderco da tela onde a area de desenho serah inserida.**/
  explicit Plotter(QWidget *parent = 0);

  /** @brief paintEvent() eh utilizado para indicar um evento de desenho
    * @param   **/
  void paintEvent(QPaintEvent *e);
  /** @brief carregaDados() eh utilizado para inserir os dados que serao desenhados no grafico,
    * recebendo-os da mainwindow e normalizando-os.
    * @param _times recebe o vetor com as informasoes de tempo.
    * @param _dados recebe o vetor com as informasoes de dados**/
  void carregaDados(vector<double> _times, vector<double> _dados);

signals:

public slots:

};

#endif // PLOTTER_H
