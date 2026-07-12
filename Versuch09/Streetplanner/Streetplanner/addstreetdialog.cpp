#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

/**
 * @brief Sets up the dialog and fills the combo boxes with city names.
 */
AddStreetDialog::AddStreetDialog(const QStringList &cityNames, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);

    // Fill both combo boxes with the same list of known city names.
    ui->comboBox_firstCity->addItems(cityNames);
    ui->comboBox_secondCity->addItems(cityNames);
}

/**
 * @brief Releases the generated user interface.
 */
AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

/**
 * @brief Returns the first city name, preferring manual input over combo-box selection.
 */
QString AddStreetDialog::getFirstCityName() const
{
    // Prefer the manual line edit if the user typed a value there.
    if (!ui->lineEdit_firstCity->text().isEmpty())
    {
        return ui->lineEdit_firstCity->text();
    }

    return ui->comboBox_firstCity->currentText();
}

/**
 * @brief Returns the second city name, preferring manual input over combo-box selection.
 */
QString AddStreetDialog::getSecondCityName() const
{
    // Prefer the manual line edit if the user typed a value there.
    if (!ui->lineEdit_secondCity->text().isEmpty())
    {
        return ui->lineEdit_secondCity->text();
    }

    return ui->comboBox_secondCity->currentText();
}
