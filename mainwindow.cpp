#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Interface 4 Advent Of Code");

    m_mainWidget = new QWidget(this);

    m_date = QDate::currentDate();

    for (int i = START_YEAR ; i < m_date.year(); i++) {
        m_year_list << QString::number(i);
    }

    for (int i = 1; i < XMAS_DAY; i++) {
        m_day_list << QString::number(i);
    }

    // Box Layout declaration
    m_vLayout = new QVBoxLayout(this);
    m_hLayout = new QHBoxLayout(this);
    m_vLayout_left = new QVBoxLayout(this);
    m_vLayout_right = new QVBoxLayout(this);
    m_hLayout_btn = new QHBoxLayout(this);

    // Label declaration
    QLabel *title = new QLabel(QString("This is an interface for Advent of Code"), m_mainWidget);
    QLabel *input_data_label = new QLabel(QString("Enter the input data:"), m_mainWidget);
    QLabel *result_label = new QLabel(QString("Here the result:"), m_mainWidget);
    QLabel *year_label = new QLabel(QString("Select the year:"), m_mainWidget);
    QLabel *day_label = new QLabel(QString("Select the day:"), m_mainWidget);
    QLabel *result = new QLabel(QString(""), m_mainWidget);

    // Button declaration
    QPushButton *clear_btn = new QPushButton(QString("Clear"), m_mainWidget);
    QPushButton *process_btn = new QPushButton(QString("Process"), m_mainWidget);
    QPushButton *submit_btn = new QPushButton(QString("Submit"), m_mainWidget);

    // Text Edit declaration
    m_input_data = new QTextEdit(QString(""), m_mainWidget);

    // Combo Box declaration
    QComboBox *year_box = new QComboBox(m_mainWidget);
    QComboBox *day_box = new QComboBox(m_mainWidget);

    // Button HLayout organization
    m_hLayout_btn->addWidget(clear_btn);
    m_hLayout_btn->addWidget(process_btn);

    // Left VLayout organization
    m_vLayout_left->addWidget(input_data_label);
    m_vLayout_left->addWidget(m_input_data);
    m_vLayout_left->addLayout(m_hLayout_btn);

    // Right VLayout organization
    m_vLayout_right->addWidget(year_label);
    m_vLayout_right->addWidget(year_box);
    m_vLayout_right->addWidget(day_label);
    m_vLayout_right->addWidget(day_box);
    m_vLayout_right->addWidget(result_label);
    m_vLayout_right->addWidget(result);
    m_vLayout_right->addWidget(submit_btn);

    // Main HLayout organization
    m_hLayout->addLayout(m_vLayout_left);
    m_hLayout->addLayout(m_vLayout_right);

    // Main VLayout organization
    m_vLayout->addWidget(title);
    m_vLayout->addLayout(m_hLayout);

    // Set MainWidget's Layout
    m_mainWidget->setLayout(m_vLayout);

    // Connections
    connect(clear_btn, SIGNAL(clicked()), this, SLOT(clear_fct()));
    connect(process_btn, SIGNAL(clicked()), this, SLOT(process_fct()));
    connect(submit_btn, SIGNAL(clicked()), this, SLOT(submit_fct()));

    year_box->addItems(m_year_list);
    day_box->addItems(m_day_list);

    setCentralWidget(m_mainWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::clear_fct()
{
    m_input_data->clear();
}

void MainWindow::process_fct()
{
    // TODO call function according to the selected puzzle's day
}

void MainWindow::submit_fct()
{
    // TODO Implement a way to make a HTTP POST with the result on advent of code web site including Authentication
}
