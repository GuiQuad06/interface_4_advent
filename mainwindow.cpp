#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Interface 4 Advent Of Code");

    m_mainWidget = new QWidget(this);

    init_date_map();

    // Box Layout declaration
    m_vLayout = new QVBoxLayout(this);
    m_hLayout = new QHBoxLayout(this);
    m_vLayout_left = new QVBoxLayout(this);
    m_vLayout_right = new QVBoxLayout(this);
    m_hLayout_btn = new QHBoxLayout(this);

    // Label declaration
    QLabel *title = new QLabel(QString("This is an interface for Advent of Code"), m_mainWidget);
    title->setAlignment(Qt::AlignHCenter);

    // Modify QFont for the title QLabel
    QFont f_title = title->font();
    f_title.setPixelSize(14);
    f_title.setPointSize(14);
    f_title.setBold(true);
    title->setFont(f_title);

    QLabel *input_data_label = new QLabel(QString("Enter the input data:"), m_mainWidget);
    QLabel *result_label = new QLabel(QString("Here the result:"), m_mainWidget);
    QLabel *timer_label = new QLabel(QString("It tooks (in sec):"), m_mainWidget);
    QLabel *year_label = new QLabel(QString("Select the year:"), m_mainWidget);
    QLabel *day_label = new QLabel(QString("Select the day:"), m_mainWidget);
    m_result = new QLabel(QString(""), m_mainWidget);
    m_time_result = new QLabel(QString(""), m_mainWidget);

    // Set a Black Border on the result QLabel to distinguish it when empty
    m_result->setFrameShape(QFrame::Shape::Box);
    m_result->setLineWidth(1);
    m_time_result->setFrameShape(QFrame::Shape::Box);
    m_time_result->setLineWidth(1);

    // Button declaration
    QPushButton *clear_btn = new QPushButton(QString("Clear"), m_mainWidget);
    QPushButton *process_btn = new QPushButton(QString("Process"), m_mainWidget);
    QPushButton *submit_btn = new QPushButton(QString("Submit"), m_mainWidget);

    // Text Edit declaration
    m_input_data = new QTextEdit(QString(""), m_mainWidget);

    // Combo Box declaration
    m_year = new QComboBox(m_mainWidget);
    m_day = new QComboBox(m_mainWidget);

    // Button HLayout organization
    m_hLayout_btn->addWidget(clear_btn);
    m_hLayout_btn->addWidget(process_btn);

    // Left VLayout organization
    m_vLayout_left->addWidget(input_data_label);
    m_vLayout_left->addWidget(m_input_data);
    m_vLayout_left->addLayout(m_hLayout_btn);

    // Right VLayout organization
    m_vLayout_right->addWidget(year_label);
    m_vLayout_right->addWidget(m_year);
    m_vLayout_right->addWidget(day_label);
    m_vLayout_right->addWidget(m_day);
    m_vLayout_right->addWidget(result_label);
    m_vLayout_right->addWidget(m_result);
    m_vLayout_right->addWidget(timer_label);
    m_vLayout_right->addWidget(m_time_result);
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

    m_year->addItems(m_year_list);
    m_day->addItems(m_day_list);

    setCentralWidget(m_mainWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::clear_fct()
{
    m_input_data->clear();
    m_result->clear();
    m_time_result->clear();
}

void MainWindow::process_fct()
{
    int status;
    QString res, input, msg;
    QMessageBox msgBox;

    QElapsedTimer timer;
    auto elapsedMilliseconds = 0;

    input = m_input_data->toPlainText();

    try {
        // Start timer
        timer.start();
        status = m_puzzleMap[{m_year->currentText().toInt(), m_day->currentText().toInt()}](res, input);
        // Stop timer
        elapsedMilliseconds = timer.elapsed();
    }
    catch (const std::bad_function_call& e) {
        msg = e.what();
        msg += "\n\nYou must implement the choosen Puzzle Engine !";
        msgBox.setText(msg);
        msgBox.exec();
    }

    if(!status) {
        // If return OK, display the result on the text field
        m_result->setText(res);
        m_time_result->setText(QString::number(elapsedMilliseconds * 0.001));
    }
}

void MainWindow::submit_fct()
{
    // TODO Implement a way to make a HTTP POST with the result on advent of code web site including Authentication
}

void MainWindow::init_date_map()
{
    int i, j;
    m_date = QDate::currentDate();

    // Display potential puzzle Year
    for (i = START_YEAR ; i < m_date.year(); i++) {
        m_year_list << QString::number(i);
    }

    // Display potential puzzle Day
    for (j = 1; j < XMAS_DAY; j++) {
        m_day_list << QString::number(j);
    }

    // Init Map
    for (i = START_YEAR ; i < m_date.year(); i++) {
        for (j = 1; j < XMAS_DAY; j++) {
            // Initialiize the unimplemented callback puzzles
            m_puzzleMap[{i, j}] = Q_NULLPTR;
        }
    }

    //Add the implemented Puzzle callbacks here...
    m_puzzleMap[{2023,1}] = puzzle_2023_1;
}
