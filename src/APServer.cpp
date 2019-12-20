#include "APServer.h"

#include "index.h"
#include "saved.h"

APServer::APServer(int port = 80)
    : _server(port)
    , _index(DEFAULTINDEX)
    ,_n(sizeof(DEFAULTINDEX))
{
}
APServer::APServer(int port, FSWrapper fsw)
    : _server(port)
    , _fsw(fsw)
    , _index(DEFAULTINDEX)
    ,_n(sizeof(DEFAULTINDEX))
{
}

APServer::APServer()
    : _server()
    , _index(DEFAULTINDEX)
    ,_n(sizeof(DEFAULTINDEX))
{
}

APServer::APServer(int port, FSWrapper fsw, const char *index, int n): _server(port), _fsw(fsw), _index(index), _n(n)
{
}

void APServer::handleIndex()
{
    _server.send_P(200, "text/html", _index, _n);
}

void APServer::handleSave()
{
    for (int i = 0; i < _server.args(); i++) {
        _fsw.WriteParameter(_server.argName(i), _server.arg(i));
    } 
    _server.send_P(200, "text/html", SAVED, sizeof(SAVED));
}

void APServer::handleRestart()
{
    Serial.println(_fsw.ReadParameter("pAPName"));
    Serial.println(_fsw.ReadParameter("pAPPassword"));
    Serial.println(_fsw.ReadParameter("pSTName"));
    Serial.println(_fsw.ReadParameter("pSTPassword"));
    Serial.println("Restarting AP...");
    delay(5000);
    ESP.restart(); //Light
    //ESP.reset(); //Hard
}

void APServer::handleClient()
{
    _server.handleClient();
}

void APServer::setAccessPoint(String name, String password)
{
    _apName = name;
    _apPassword = password;
    _fsw.WriteParameter("pAccessPointSSID", name);
    _fsw.WriteParameter("pAccessPointPassword", password);
    
    delay(500);
}

void APServer::startAccessPoint()
{
    _apName = _fsw.ReadParameter("pAccessPointSSID");
    _apPassword = _fsw.ReadParameter("pAccessPointPassword");
    if(_apName == ""){
        String name = WiFi.softAPmacAddress();
        WiFi.softAP(name.c_str(), "12345678"); 
    }else{
        WiFi.softAP(_apName, _apPassword);
    }

    _server.on("/", std::bind(&APServer::handleIndex, this));
    _server.on("/submit", std::bind(&APServer::handleSave, this));
    _server.on("/reset", std::bind(&APServer::handleRestart, this));
    _server.begin();

    Serial.println("AccessPoint Listening");
}