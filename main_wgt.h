#ifndef MAINWGT_T_H
#define MAINWGT_T_H

#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

#include "crc_32.h"
#include "employee.h"

class MainWgt_t : public QWidget
{
    Q_OBJECT
private:
    std::vector<Employee_t> vecEmpl;
    QTimer *timerBtnCheckP = new QTimer(this);
protected:
// Frame for Adjust:
    QLabel *labelAdjustP;
    QFrame *frameAdjustP;
    QVBoxLayout *frameAdjustLayoutP;
// layout 1:
    // layout 1.1:
    QLabel* lblNameP;
    QLineEdit* ledNameP;
    // layout 1.2:
    QLabel* lblSurnameP;
    QLineEdit* ledSurnameP;
    // layout 1.3:
    QLabel* lblMiddleNameP;
    QLineEdit* ledMiddleNameP;
// layout 2:
    QLabel* lblSexP;
    QComboBox* cmbboxSexP;
    QLabel* lblAgeP;
    QSpinBox* spnbAgeP;
    QLabel* lblExperienceP;
    QSpinBox* spnbExperienceP;
// layout 3:
    QLabel* lblPhoneNumberP;
    QLineEdit* ledPhoneNumberP;
// layout 4:
    QLabel* lblFindEmplP;
    QLineEdit* ledFindEmplP;
    QPushButton* btbFindEmplP;
// layout 5:
    QPushButton *btnAddEmployeeP;
    QPushButton *btnDeleteEmployeeP;
    QLabel* lblQuantityEmplP;
    QLabel* lblQuantityEmplModeP;
// layout 6:
    QGroupBox *grbxBtnPnlP;
    QPushButton* btnWriteFileP;
    QPushButton* btnWriteAndModifyFileP;
    QPushButton* btnCheckFileP;
    // layout 6.1:
    QLabel* lblCrcP;
    QLabel* lblCrcModeP;
    QLabel* lblInputRangeP;
    QLineEdit* ledInputRangeP;

public:
    MainWgt_t(QWidget* parent = nullptr);
    ~MainWgt_t();

    QLabel* createQLabel(const char *str = "");
    QLabel* createNameQLabel(const char *str = "");
    QComboBox* createQComboBox();
    QPushButton* createPushButton(const char* str = "");
    QLineEdit* createQLineEdit();

    void FillEmployeeListFromFile(const QByteArray& bytar, size_t size);

public slots:
    void slotAddEmployee();
    void slotDeleteEmployee();
    void slotFindEmployee();
    void slotCheckID(QString id);
    void slotCheckRange(QString id);
    void slotWritefile();
    void slotWriteModifyFile();
    void slotCheckFile();
    void slotColorBtn();
};
#endif // MAINWGT_T_H
