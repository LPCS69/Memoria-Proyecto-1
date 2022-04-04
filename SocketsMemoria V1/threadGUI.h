//
// Created by pablo on 2/4/22.
//

#ifndef SOCKETSMEMORIA_THREADGUI_H
#define SOCKETSMEMORIA_THREADGUI_H

#include <QThread>

class threadGUI : public QThread
        {
    Q_OBJECT
        public:
            explicit threadGUI(QObject *parent = 0);

protected:
            void run();
};


#endif //SOCKETSMEMORIA_THREADGUI_H
