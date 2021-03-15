#ifndef TWOWAYBINDINGTEXT_H
#define TWOWAYBINDINGTEXT_H

#include <QObject>

class TwoWayBindingText : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString myValue READ getValue WRITE setValue NOTIFY valueChanged )
public:
    TwoWayBindingText();
    QString getValue();

public slots:
    void setValue( QString value );

signals:
    void valueChanged();

private:
    QString m_value;


signals:

};

#endif // TWOWAYBINDINGTEXT_H
