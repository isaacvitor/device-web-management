#include "APServer.h"

#include "index.h"
#include "saved.h"

APServer::APServer(int port = 80)
    : _server(port)
{
}
APServer::APServer(int port, FSWrapper fsw)
    : _server(port)
{
    _fsw = fsw;
}

APServer::APServer()
    : _server()
{
}

void APServer::handleIndex()
{
    _server.send_P(200, "text/html", INDEX, sizeof(INDEX));
}

void APServer::handleSave()
{
    static String params = "";
    String apSSID = _server.arg("pAP-SSID");
    String apPassword = _server.arg("pAP-Password");
    String stSSID = _server.arg("pST-SSID");
    String stPassword = _server.arg("pST-Password");

    _fsw.WriteParameter("pAPName", apSSID);
    _fsw.WriteParameter("pAPPassword", apPassword);
    _fsw.WriteParameter("pSTName", stSSID);
    _fsw.WriteParameter("pSTPassword", stPassword);

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
    if(_fsw != null){
        _fsw.WriteParameter("pAPName", name);
        _fsw.WriteParameter("pAPPassword", password);
    }
    
    delay(500);
}

void APServer::startAccessPoint()
{
    _apName = _fsw.ReadParameter("pAPName");
    _apPassword = _fsw.ReadParameter("pAPPassword");
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