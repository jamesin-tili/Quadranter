#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);

    if (!read_settings_file("settings.cfg"))
    {
        qDebug() << "Reading the settings file failed, resorting to defaults";
        title = "Quadranter 2000";
        list1  << "Eka texsti" << "Toka teksti" << "arvaa mones?";
        list2 = list1;
        list3 = list1;
        list4 = list1;
        listNames.clear();
        listNames << "List 1" << "List 2" << "List 3" << "List 4";
    }

    setWindowTitle(title);

    // Create models
    MyStringListModel *model1 = new MyStringListModel(list1);
    MyStringListModel *model2 = new MyStringListModel(list2);
    MyStringListModel *model3 = new MyStringListModel(list3);
    MyStringListModel *model4 = new MyStringListModel(list4);

    // Create views
    MyListView *lview1 = new MyListView(model1);
    MyListView *lview2 = new MyListView(model2);
    MyListView *lview3 = new MyListView(model3);
    MyListView *lview4 = new MyListView(model4);

    // Create quadrants
    QWidget *quadrant1 = create_quadrant(listNames.at(0), lview1);
    QWidget *quadrant2 = create_quadrant(listNames.at(1), lview2);
    QWidget *quadrant3 = create_quadrant(listNames.at(2), lview3);
    QWidget *quadrant4 = create_quadrant(listNames.at(3), lview4);

    // Set final layout
    QGridLayout *gLayout = new QGridLayout();
    gLayout->addWidget(quadrant1,0,0);
    gLayout->addWidget(quadrant2,0,1);
    gLayout->addWidget(quadrant3,1,0);
    gLayout->addWidget(quadrant4,1,1);

    QWidget *allQuadrants = new QWidget();
    allQuadrants->setLayout(gLayout);
    setCentralWidget(allQuadrants);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::create_quadrant(QString title, MyListView *listView)
{
    QLabel *label = new QLabel(title);
    label->setAlignment(Qt::AlignCenter);
    //    VerticalLabel *vlabel1 = new VerticalLabel("Pystylaabelia");

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(label);
    vLayout->addWidget(listView);

    QWidget *package = new QWidget();
    package->setLayout(vLayout);

    return package;
}

// Reads a settings text file and returns the contents for the
/* TBD: should store data in local variables until the file is
 * read until the end, and not update the class variables before
 * that.
*/
bool MainWindow::read_settings_file(QString filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream textStream(&file);
    QString line, lineHeader;
    QStringList lineContents;

    while (!textStream.atEnd())
    {
        line = textStream.readLine();
        lineContents = line.split(";");

        // the 1st word defines what the line contains
        lineHeader = lineContents.at(0);
        if (lineHeader == "#TITLE") {
            title = lineContents.at(1);

        } else if (lineHeader == "#LISTS") {
            title = lineContents.at(1);
            listNames.clear();
            for (int i = 1; i<5; i++) {
                listNames << lineContents.at(i);
            }

        } else if (lineHeader == "#LIST1") {
            list1.clear();
            for (int i = 1; i<lineContents.length(); i++) {
                list1 << lineContents.at(i);
            }

        } else if (lineHeader == "#LIST2") {
            list2.clear();
            for (int i = 1; i<lineContents.length(); i++) {
                list2 << lineContents.at(i);
            }

        } else if (lineHeader == "#LIST3") {
            list3.clear();
            for (int i = 1; i<lineContents.length(); i++) {
                list3 << lineContents.at(i);
            }
        } else if (lineHeader == "#LIST4") {
            list4.clear();
            for (int i = 1; i<lineContents.length(); i++) {
                list4 << lineContents.at(i);
            }
        }
    }

    file.close();
    return true;

}

