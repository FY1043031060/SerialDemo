#ifndef XXXX_H
#define XXXX_H

#include <QtWidgets/QMainWindow>
#include <QRunnable>
#include <QThread>
#include "f2900_sdk.h"
#include "ui_xxxx.h"

#define ARR_SIZE 90000
typedef enum
{
    CAN_PORT = 9,
    ARINC429_PORT
} SERIAL_SEL_T;

class RecvData: public QObject
{
    Q_OBJECT
public:
    RecvData(QObject *parent = 0)
    {
        ucArrTemp = (unsigned char*)malloc(ARR_SIZE);
        memset(ucArrTemp, 0, ARR_SIZE);
        m_iCurrentIndex = 0;
    }
public:
    unsigned char* ucArrTemp;
    int m_iCurrentIndex;
private:
    ~RecvData()
    {
        if(ucArrTemp != NULL)
        {
            free(ucArrTemp);
        }
        ucArrTemp = NULL;
    }
signals:
    void textChanged(QString strTemp);
public slots:
    void run()
    {
        QString strTemp = "";
        int uiTemp = -1;
        while(uiTemp)
        {
            QThread::msleep(10);
            switch(m_iCurrentIndex)
            {
                case RS422_ASYN1_PORT:
                case RS422_ASYN2_PORT:
                case RS422_ASYN3_PORT:
                case RS422_ASYN4_PORT:
                case RS422_ASYN5_PORT:
                case RS422_ASYN6_PORT:
                case RS422_SYN1_PORT:
                case RS422_ASYN1_EXTRA_SERIAL:
                case RS422_ASYN2_EXTRA_SERIAL:
                    ReadRS422Port((RS422_SERIAL_TYPE_T)m_iCurrentIndex, ucArrTemp, ARR_SIZE, &uiTemp);
                    break;
                case CAN_PORT:
                    ReadCANPort(ucArrTemp, ARR_SIZE, &uiTemp);
                    break;
                case ARINC429_PORT:
                    ReadARINC429Port((unsigned int*)ucArrTemp, ARR_SIZE / 4, &uiTemp);
                    break;
            }

        }
        if(m_iCurrentIndex == ARINC429_PORT)
        {
            strTemp += QByteArray((char*)ucArrTemp, uiTemp * 4);
        }
        else
            strTemp += QByteArray((char*)ucArrTemp, uiTemp);
        textChanged(strTemp);
    }

    void onComboClicked(int index)
    {
        this->m_iCurrentIndex = index;
    }
};

class XXXX : public QMainWindow
{
    Q_OBJECT
public:
    XXXX(QWidget *parent = 0);
    ~XXXX();
    int initCombox();
    int initConnect();
    int initItemCombox();

private slots:
    void onComboxChoosed(int index);
    void onSendButtonClicked();
    void onTextChanged(QString strTemp);
private:
    Ui::XXXXClass ui;
    RecvData* pRecvData;
    QThread recvThread;
};

#endif // XXXX_H
