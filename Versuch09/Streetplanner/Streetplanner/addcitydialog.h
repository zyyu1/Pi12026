#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include "city.h"

#include <QDialog>

namespace Ui {
class AddCityDialog;
}

/**
 * @brief Dialog for entering the data of a new city.
 */
class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creates the add-city dialog.
     * @param parent Parent widget.
     */
    explicit AddCityDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the dialog.
     */
    ~AddCityDialog();

    /**
     * @brief Creates a city from the current dialog input.
     * @return New city object or nullptr if the input is invalid.
     */
    City* createCity() const;

private:
    ///< Designer-generated user interface.
    Ui::AddCityDialog *ui;
};

#endif // ADDCITYDIALOG_H
