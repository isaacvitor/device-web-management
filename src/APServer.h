#ifndef ESP8266WEBSERVER_H
#include <ESP8266WebServer.h>
#endif

#ifndef FSWRAPPER_H
#include <FSWrapper.h>
#endif

#ifndef APSERVER_H
#define APSERVER_H


class APServer{
  public:
    APServer(int port);
    APServer(int port, FSWrapper fsw);
    APServer();
    void handleClient();
    void setAccessPoint(String name, String password);
    void startAccessPoint();

  protected:
    FSWrapper _fsw;
    ESP8266WebServer _server;
    String _apName;
    String _apPassword;
    void handleIndex();
    void handleSave();
    void handleRestart();
};

#endif