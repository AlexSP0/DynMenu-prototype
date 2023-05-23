#ifndef COMMAND_H
#define COMMAND_H

#include <QAction>
#include <QMenu>
#include <QObject>
#include <QUuid>

#include <memory>

/*!
 * \brief Container for QAction object
 *
 * The container contains additional information about the QAction type object,
 * such as ID and text.
 *
 */

class Command : public QObject
{
public:
    Q_OBJECT
public:
    /*!
    Creates container with specified QAction
    \param[in] action pointer to QAction object
    */
    Command(QAction *action);

    /*!
    Return the ID of container
    \return ID of container
    */
    QUuid getId();

    /*!
    Compares two containers by ID
    \param[in] other reference to the container with which the comparison is made
    \return returns true if the id of the containers is the same, false if they are different
    */
    bool operator==(const Command &other);

    /*!
    Returns pointer to QAction object in this container
    \return pointer to QAction object
    */
    QAction *getAction();

    /*!
    Returns text in this container
    \return Returns text
    */
    QString &getText();

    /*!
    Sets the string for the container
    \param[in] text string to be set
    */
    void setText(QString text);

private:
    QUuid m_id;

    QAction *m_action;

    QString m_text = "";

    //TO DO add QKeySequence, QIcon and etc
};

#endif // COMMAND_H
