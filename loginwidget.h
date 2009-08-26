/*
Copyright (c) 2009, ImageShack Corp.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the ImageShack nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QtGui/QStackedWidget>
#include "loginrequest.h"

namespace Ui {
    class LoginWidget;
}

class LoginWidget : public QStackedWidget {
    Q_OBJECT
    Q_DISABLE_COPY(LoginWidget)
public:
    explicit LoginWidget(QWidget *parent = 0);
    virtual ~LoginWidget();
    bool isLoggedIn();
    QString getCookie();
    void setLoggedIn(bool value);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::LoginWidget *m_ui;
    QString cookie;
    bool loggedIn;
    LoginRequest request;
    void saveCookie();
    bool loadCookie();
    bool forgetCookie();
    QString username;

private slots:
    void logIn();
    void logOut();
    void successReceiver(QString, QString);
    void failReceiver();
    void wrongPasswordReceiver();
    void cancel();
    void rememberChange();

signals:
    void loginStatus(int); // 0 - logged in; 1 - logged out;
};

#endif // LOGINWIDGET_H
