const char SAVED[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0, shrink-to-fit=no" />
    <title>Device Config</title>
    <style>
      body {
        background: #CCC;
        background: -webkit-linear-gradient(right, #8dc26f, #3fd6c2);
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
        min-height: 170px;
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
      /* .form p {
        color:#000;
        width: 100%;
        margin: 0 0 15px;
        padding: 15px;
        font-size: 18px;
      } */
      .bt {
        font-family: Roboto, sans-serif;
        text-align: center;
        text-transform: uppercase;
        text-decoration: none;
        background: #4caf50;
        display:block;
        width: 91%;
        padding: 15px;
        color: #fff;
        font-size: 14px;
        -webkit-transition: all 0.3 ease;
        transition: all 0.3 ease;
        cursor: pointer;
      }
      .bt:active,
      .bt:focus,
      .bt:hover {
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

      .center{
        text-align: center;
      }
      .warnig-message {
        font-size: 15px;
        font-weight: bold;
        color: rgb(255, 51, 0);
        text-align: left;

      }
      #countViewer{
        color: crimson;
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
        <div class="row"><p>Device parameters saved successufully</p></div>
        <div class="row">
          <p class="warnig-message">Be sure to remove wire connected between GPIO3(RX pin) PIN and Ground PIN </p>
          <p class="center">Reset device in <span id="countViewer"></span> seconds</p>
        </div>
        
        <div><a href="/reset" class="bt">Reset Device Now</a></div>
      </div>
    </div>
  </body>
  <script>
    count = 30;
    countViewer = document.getElementById('countViewer');

    countdownFunction = ()=> { 
      if (count >= 0) {
        showCountdown(count);
        count--;
      } else {
        clearInterval(countInterval);
        resetDevice();
      }
    }
    showCountdown = (t) => countViewer.innerText = t
    resetDevice = () => window.location.href = '/reset'
    
    countInterval = setInterval(countdownFunction, 1000)
  </script>
</html>
)=====";