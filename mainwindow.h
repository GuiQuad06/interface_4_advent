#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <functional>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QDate>
#include <QString>
#include <QFont>
#include <QMap>

#define START_YEAR    2015    // First year of Advent of Code
#define XMAS_DAY        25

using PuzzleFunction = std::function<int(QString&, const QString&)>;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_date_map();

private slots:
    void clear_fct();
    void process_fct();
    void submit_fct();

private:
    QStringList m_year_list;
    QStringList m_day_list;

    QVBoxLayout* m_vLayout;
    QVBoxLayout* m_vLayout_left;
    QVBoxLayout* m_vLayout_right;
    QHBoxLayout* m_hLayout;
    QHBoxLayout* m_hLayout_btn;

    QWidget* m_mainWidget;
    QTextEdit* m_input_data;
    QComboBox* m_year;
    QComboBox* m_day;
    QLabel* m_result;

    QDate m_date;

    QMap<std::pair<int, int>, PuzzleFunction> m_puzzleMap;

};
#endif // MAINWINDOW_H
