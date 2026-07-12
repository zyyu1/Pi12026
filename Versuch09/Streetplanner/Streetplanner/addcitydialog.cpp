#include "addcitydialog.h"
#include "ui_addcitydialog.h"

#include <QMessageBox>

/**
 * @brief Sets up the dialog widgets.
 */
AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Releases the generated user interface.
 */
AddCityDialog::~AddCityDialog()
{
    delete ui;
}

/**
 * @brief Creates a city from the current dialog input fields.
 */
City* AddCityDialog::createCity() const
{
    // Read the raw values from the dialog widgets.
    QString name = ui->lineEdit_cityName->text();

    bool xInt = false;
    bool yInt = false;

    int x = ui->lineEdit_x->text().toInt(&xInt);
    int y = ui->lineEdit_y->text().toInt(&yInt);

    // Reject incomplete or non-numeric input.
    if (name.isEmpty() || !xInt || !yInt)
    {
        return nullptr;
    }

    // Create the city only after all validation checks have passed.
    return new City(name, x, y);
}
