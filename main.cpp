/*
 *
 * An App To Study Qt
 * Console Linux App (C) 2020
 * Foxoman  email: sultan@foxoman.net
 *
 */

#include <QCoreApplication>
#include <QRegularExpression>
#include <QTextStream>
#include <QThread>
#include <QTimer>
#include <QDebug>

#define APP_VERSION "1.0.0"

#define RESET       "\033[0m"
#define BLACK       "\033[30m"        /* Black */
#define RED         "\033[31m"        /* Red */
#define GREEN       "\033[32m"        /* Green */
#define YELLOW      "\033[33m"        /* Yellow */
#define BLUE        "\033[34m"        /* Blue */
#define MAGENTA     "\033[35m"        /* Magenta */
#define CYAN        "\033[36m"        /* Cyan */
#define WHITE       "\033[37m"        /* White */
#define BOLDBLACK   "\033[1m\033[30m" /* Bold Black */
#define BOLDRED     "\033[1m\033[31m" /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m" /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m" /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m" /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m" /* Bold White */

// Qt stdin/stdout like cin/cout in C++
static QTextStream qin( stdin, QIODevice::ReadOnly );
static QTextStream qout( stdout, QIODevice::WriteOnly );

// typewriter like animation
void slow_print( QString msg )
{
    foreach ( const QChar& c, msg ) {
        qout << c << flush;
        QThread::msleep( 30 );
    }
}

QString toBitString( const QVariant& v )
{
    const QByteArray bytes = v.toByteArray(); // Convert the String to QByteArray
    QString          bitString;

    // Iterare the QByteArray
    for ( QByteArray::const_iterator singlebyte = bytes.begin(); singlebyte != bytes.end();
          ++singlebyte ) {
        // Get the Binary Number of each Iter of the QByteArray and append it to
        // the final String!
        bitString.append( QString::number( *singlebyte, 2 ) );
    }

    return QString( bitString )
            .replace( QRegularExpression( "(.{7})" ),
                      "\\1 " ); // Add space after each byte using regex
}

int main( int argc, char* argv[] )
{
    QCoreApplication app( argc, argv );

    // Set the app Information for windows!
    app.setApplicationName( "String To Binary Converter" );
    app.setOrganizationName( "Foxoman" );
    app.setOrganizationDomain( "foxoman.net" );
    app.setApplicationVersion( APP_VERSION );

    // Dev signature in Raw QString
    const QString fox = R"(

                        |\__/|
                       /     \
                      /_.~ ~,_\   -foxoman
                         \@/

            String to Binary Converter @ 2020 v: ##VERSION##
            Made with love using Qt      #100DaysOfCode
            www.foxoman.net  ||  sultan@foxoman.net

                    )";

    // Print the Dev Signature using qPrintable and set the app version!
    qInfo() << BOLDYELLOW << qPrintable( QString( fox ).replace( "##VERSION##", APP_VERSION ) )
            << RESET;

    QThread::sleep( 1 ); // Sleep for 1 secounds before printing the next line

    // forvever Qt Loop
    forever {
        slow_print( "\n********************************* TO EXIT TYPE (q)!" );
        QThread::sleep( 1 );

        qInfo() << BOLDMAGENTA;
        slow_print( "\n********************************* WRITE THE TEXT:" );
        qInfo() << RESET << BOLDGREEN;

        const QString txt = qin.readLine(); // Read the stream line

        if ( txt == "q" ) // quit the loop and the app if the user input q
            break;

        QThread::sleep( 1 );
        qInfo() << RESET << BOLDBLUE;
        slow_print( "\n********************************* BINARY:" );
        qInfo() << RESET << BOLDRED;

        slow_print( toBitString( txt.trimmed() ) );
        qInfo() << RESET;

        QThread::sleep( 2 );
    }

    qInfo() << RESET;

    QTimer::singleShot( 0, &app, &QCoreApplication::quit ); // quit the app
    return app.exec();
}
