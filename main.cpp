#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include "board/BoardFactory.h"
#include "board/chessviewmodel.h"
#include "twowaybindingtext.h"
#include "twowaybindingsquare.h"
#include "twowaybindinglistsquare.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    BoardFactory::createBoard();

    QQmlApplicationEngine engine;
    ChessViewModel chessVm;
    chessVm.setBoard(*BoardFactory::createBoard());

    TwoWayBindingText * text = new TwoWayBindingText();

    TwoWayBindingSquare * square = new TwoWayBindingSquare();

    TwoWayBindingListSquare * listsquare = new TwoWayBindingListSquare();

    engine.rootContext()->setContextProperty("gameBoard", &chessVm);
    engine.rootContext()->setContextProperty("MyModel", text);
    engine.rootContext()->setContextProperty("MySquareModel", square);
    engine.rootContext()->setContextProperty("MySquareListModel", listsquare);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

