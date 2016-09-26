#include "xxxx.h"
XXXX::XXXX(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    InitMediaDll();
    initCombox();
    initItemCombox();
    pRecvData = new RecvData();
    pRecvData->moveToThread(&recvThread);
    initConnect();
    recvThread.start();
}

XXXX::~XXXX()
{
    UnInitMediaDll();
}

int XXXX::initCombox()
{
    int iRet = 0;
    ui.m_comboBox->insertItem(0, "choose serial", "");

    ui.m_comboBox->insertItem(1, "RS422_ASYN1", RS422_ASYN1_PORT);
    ui.m_comboBox->insertItem(2, "RS422_ASYN2", RS422_ASYN2_PORT);
    ui.m_comboBox->insertItem(3, "RS422_ASYN3", RS422_ASYN3_PORT);
    ui.m_comboBox->insertItem(4, "RS422_ASYN4", RS422_ASYN4_PORT);
    ui.m_comboBox->insertItem(5, "RS422_ASYN5", RS422_ASYN5_PORT);
    ui.m_comboBox->insertItem(6, "RS422_ASYN6", RS422_ASYN6_PORT);
    ui.m_comboBox->insertItem(7, "RS422_SYN1", RS422_SYN1_PORT);
    ui.m_comboBox->insertItem(8, "RS422_EXTRA_ASYN1", RS422_ASYN1_EXTRA_SERIAL);
    ui.m_comboBox->insertItem(9, "RS422_EXTRA_ASYN2", RS422_ASYN2_EXTRA_SERIAL);
    ui.m_comboBox->insertItem(10, "CAN", CAN_PORT);
    ui.m_comboBox->insertItem(11, "ARINC429", ARINC429_PORT);

    return iRet;
}

int XXXX::initConnect()
{
    int iRet = 0;
    QObject::connect(ui.m_comboBox, SIGNAL(activated(int)), this, SLOT(onComboxChoosed(int)));
    QObject::connect(ui.m_pushButton, SIGNAL(clicked()), this, SLOT(onSendButtonClicked()));
    QObject::connect(&recvThread, &QThread::finished, pRecvData, &QObject::deleteLater);
    QObject::connect(ui.m_comboBox, SIGNAL(activated(int)), pRecvData, SLOT(onSendButtonClicked(int)));
    QObject::connect(ui.m_pushButton, &QPushButton::clicked, pRecvData, &RecvData::run);
    QObject::connect(pRecvData, &RecvData::textChanged, this, &XXXX::onTextChanged);
    return iRet;
}

int XXXX::initItemCombox()
{
    int iRet = 0;
    ui.m_itemComboBox->insertItem(0, "BAUDRATE_9600", BAUDRATE_9600);
    ui.m_itemComboBox->insertItem(1, "BAUDRATE_14400", BAUDRATE_14400);
    ui.m_itemComboBox->insertItem(2, "BAUDRATE_19200", BAUDRATE_19200);
    ui.m_itemComboBox->insertItem(3, "BAUDRATE_38400", BAUDRATE_38400);
    ui.m_itemComboBox->insertItem(4, "BAUDRATE_56000", BAUDRATE_56000);
    ui.m_itemComboBox->insertItem(5, "BAUDRATE_57600", BAUDRATE_57600);
    ui.m_itemComboBox->insertItem(6, "BAUDRATE_115200", BAUDRATE_115200);
    ui.m_itemComboBox->insertItem(7, "BAUDRATE_128000", BAUDRATE_128000);
    return iRet;
}

void XXXX::onComboxChoosed(int index)
{
    CloseARINC429Port();
    CloseCANPort();
    for(int varSerial = RS422_ASYN1_PORT; varSerial < MAX_SERIAL_PORT_NUM; varSerial++)
    {
        CloseRS422Port((RS422_SERIAL_TYPE_T)varSerial);
    }

    QVariant varTemp = ui.m_comboBox->itemData(index);

    if(varTemp == CAN_PORT)
    {
        OpenCANPort();
        return;
    }
    else if(varTemp == ARINC429_PORT)
    {
        OpenARINC429Port(BAUDRATE_100KPS);
        return;
    }

    QVariant varBaudrate = ui.m_itemComboBox->itemData(index);
    OpenRS422Port((RS422_SERIAL_TYPE_T)(varTemp.toInt()), (BAUDRATE_NORMAL_T)varBaudrate.toInt());

}

void XXXX::onSendButtonClicked()
{
    QVariant varSelect = ui.m_comboBox->currentData();
    QByteArray arrTemp = ui.m_sendTextEdit->toPlainText().toLatin1();
    switch(varSelect.toInt())
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

            WriteRS422Port((RS422_SERIAL_TYPE_T)varSelect.toInt(), (unsigned char*)arrTemp.constData(), arrTemp.length());
            break;
        case CAN_PORT:
            WriteCANPort((unsigned char*)arrTemp.constData(), arrTemp.length());
            break;
        case ARINC429_PORT:
            WriteARINC429Port((unsigned int*)arrTemp.data(), arrTemp.length() / 4);
            break;
        default:
            break;
    }
}

void XXXX::onTextChanged(QString strTemp)
{
    ui.m_recvTextEdit->setPlainText(strTemp);
}
