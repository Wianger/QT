#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <surakartagame.h>
#include <QTimer>
#include <surakartaboard.h>
#include <QMessageBox>
#include "../src/networksocket.h"
#include <QDialog>
#include "surakartaagent.h"
#include <QFile>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(unsigned int b = 6, unsigned int c = 10, QString player = "BLACK", QString username = "Team7",
               QString room = "1", int port = 10086, unsigned int round = 40, QWidget *parent = nullptr);
    ~MainWindow();
    void updatePlayerInfo();
    void endGame(QString, QString, QString);
    void restartGame();
    void connected_successfully();
    void connectToServer();
    void disconnectFromServer();
    void sendMessage(OPCODE, QString, QString, QString);
    void receiveMessage(NetworkData);
    void Move(SurakartaMove);


private:
    Ui::MainWindow *ui;
    SurakartaGame *game;
    unsigned int CountDown, restTime;
    QTimer *timer;
    NetworkSocket *socket;
    int port;
    QString ip = "127.0.0.1";
    QString username, room;
    SurakartaAgent *agent;
    bool is_ai = false;
    QFile file;
    qsizetype step = 0;
    QString record;
    QStringList move;

private slots:
    void on_move_clicked();
    void updateCountdown();
    void on_resigne_clicked();
    void on_send_msg_clicked();
    void on_ai_clicked();
    void on_prompt_clicked();
    void on_reappear_clicked();
};

#endif // MAINWINDOW_H
