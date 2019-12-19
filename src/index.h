const char DEFAULTINDEX[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0, shrink-to-fit=no" />
    <title>Device Config</title>
    <style>
      body {
        background: #CCC;
        background: -webkit-linear-gradient(right, #8dc26f, #5ac4b5);
        background: -moz-linear-gradient(right, #8dc26f, #3fd6c2);
        background: -o-linear-gradient(right, #8dc26f, #3fd6c2);
        background: linear-gradient(to left, #8dc26f, #3fd6c2);
        font-family: Roboto, sans-serif;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
      }
     
      .config-page {
        width: 360px;
        padding: 8% 0 0;
        margin: auto;
      }
      .form {
        position: relative;
        z-index: 1;
        background: #fff;
        max-width: 360px;
        margin: 0 auto 100px;
        padding: 10px;
        text-align: left;
        box-shadow: 0 0 5px 0 rgba(0, 0, 0, 0.2), 0 2px 2px 0 rgba(0, 0, 0, 0.24);
      }
      .form div span {
        font-size: 1em;
        font-weight: bold;
        letter-spacing: -1px
      }
      .form div h1 {
        margin:0 0 15px 0;
        letter-spacing: -2px
      }
      .form input {
        outline: 0;
        background: #f2f2f2;
        width: 100%;
        border: 1px solid #ccc;
        margin: 0 0 15px;
        padding: 15px;
        box-sizing: border-box;
        font-size: 14px;
      }
      .form input:focus {
        border: 1px solid #3fd6c2;
      }
      .form button {
        font-family: Roboto, sans-serif;
        text-transform: uppercase;
        outline: 0;
        background: #4caf50;
        width: 100%;
        border: 0;
        padding: 15px;
        color: #fff;
        font-size: 14px;
        -webkit-transition: all 0.3 ease;
        transition: all 0.3 ease;
        cursor: pointer;
      }
      .form button:active,
      .form button:focus,
      .form button:hover {
        background: #43a047;
      }

      .column {
        float: left;
        width: 50%;
      }

      /* Clear floats after the columns */
      .row:after {
        content: "";
        display: table;
        clear: both;
      }

      .logo{
        text-align: right;
      }
    </style>
  </head>
  <body>
    <div class="config-page">
      <div class="form">
          <div class="row">          
              <div class="column">
                <span>Device</span>
                <h1>PARAMETERS</h1>
              </div>
              <div class="column logo">
                  <svg version="1.1" id="Camada_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                      width="50px" height="53.8px" viewBox="0 0 100 103.8" style="enable-background:new 0 0 100 103.8;" xml:space="preserve">
                    <style type="text/css">
                        .st0{fill:#00FF00;}
                    </style>
                    <polygon class="st0" points="100,40.7 0,0 0,22.6 72.2,51.9 0,81.3 0,103.8 100,63.2 100,63.2 100,63.2 100,40.7 100,40.6 "/>
                  </svg>
              </div>
            </div>
        
        <form class="config-form" action="http://192.168.4.1/submit" method="post">
          <input type="text" name="pAP-SSID" placeholder="Access Point SSID" />
          <input type="password" name="pAP-Password" placeholder="Access Point SSID Password" />
          <input type="text" name="pST-SSID" placeholder="SSID" />
          <input type="password" name="pST-Password" placeholder="SSID Password" />
          <button>Save</button>
        </form>
      </div>
    </div>
  </body>
</html>
)=====";
