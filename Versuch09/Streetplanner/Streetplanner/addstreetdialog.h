#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class AddStreetDialog;
}

/**
 * @brief Dialog for choosing the two endpoint cities of a new street.
 */
class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Creates the add-street dialog.
     * @param cityNames Names used to fill the combo boxes.
     * @param parent Parent widget.
     */
    explicit AddStreetDialog(const QStringList &cityNames, QWidget *parent = nullptr);

    /**
     * @brief Destroys the dialog.
     */
    ~AddStreetDialog();

    /**
     * @brief Returns the first selected or manually entered city name.
     * @return Name of the first city.
     */
    QString getFirstCityName() const;

    /**
     * @brief Returns the second selected or manually entered city name.
     * @return Name of the second city.
     */
    QString getSecondCityName() const;

private:
    ///< Designer-generated user interface.
    Ui::AddStreetDialog *ui;
};

#endif // ADDSTREETDIALOG_H
