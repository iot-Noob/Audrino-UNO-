/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "";
const char* password = "";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output5 = 5;
const int output4 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(9600);
  // Initialize the output variables as outputs
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
         
            
            // Display the HTML web page
             client.println("<html>");
client.println("<head>");
client.println("<script src='http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js'></script> ");
client.println("      <link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/css/bootstrap.min.css' integrity='sha384-xOolHFLEh07PJGoPkLv1IbcEPTNtaed2xpHsD9ESMhqIYd0nLMwNLD69Npy4HI+N' crossorigin='anonymous'> "); 
client.println("      <script src='https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js' integrity='sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj' crossorigin='anonymous'></script>");
client.println("      <script src='https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/js/bootstrap.bundle.min.js' integrity='sha384-Fy6S3B9q64WdZWQUiU+q4/2Lc9npb8tCaSX9FK7E8HnRr0Jz8D6OP9dO5Vg3Q9ct' crossorigin='anonymous'></script>");
client.println("      <title>Barqi labs Weather Station </title>");
client.println("      <link rel='icon' href='data:image/png;base64,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'>");
client.println("      <meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println("      <link href='https://fonts.googleapis.com/css?family=Open+Sans:300,400,600' rel='stylesheet'>");
  
client.println("      <style>");
    
client.println("     .sio{");
client.println("      text-align:center;");
client.println("     width: 33px;");
    
client.println("     }");
client.println("     .sio4{");
client.println("      text-align:center;");
client.println("     width: 22px;");
     
client.println("     }");
client.println("     .sio5{");
client.println("      text-align:center;");
client.println("     width: 11px;");
     
client.println("     }");
client.println("     .tdc{");
client.println("     vertical-align: middle;");
     
client.println("     }");
client.println("     .cc{");
client.println("      color: green;");
client.println("      font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;");
client.println("     }");
    
client.println("     .jtc{");
      
client.println("     }");
  
client.println("     .main{");
client.println("      font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;");
client.println("     text-align: left;");
client.println("      background-color:rgb(255, 255, 255);");
client.println("     }");
   
client.println("      </style>");
     
client.println("  </head>");
 
client.println("      <body class='main'>");
      
client.println("      <!--Jumbotron start-->");
 
client.println("      <div class='jumbotron jtc jumbotron-fluid'>");
          
client.println("          <div class='container'>");
           
client.println("            <h1 class='display-4 cc'>CLEAN GREEN ENVIRONNMENT</h1>");
client.println("            <p class='lead'>Detection of Volatile Organic Compound_(VOC) in wastebin a step toword Environmental sustainability</p>");
           
client.println("          </div>");
client.println("        </div>");
  
client.println("      <!--Jumbotron end-->");
    
client.println("      <br>");
client.println("      <br>");
client.println("      <!--Table Start fetch user data-->");
      
client.println("      <div class='container'>");
     
client.println("       <div class='row'>");
   
client.println("      <div class='col'>");
      
client.println("        <div  class='dropdown'  >");
client.println("          <button   class='btn btn-secondary dropdown-toggle' type='button' data-toggle='dropdown' aria-expanded='false'   >");
client.println("          Visible values by");
client.println("          </button>");
client.println("          <div id='ddl'  class='dropdown-menu'   >");
client.println("            <p    class='dropdown-item' >None</p>");
client.println("            <p   class='dropdown-item' >Current Sensor Values</p>");
client.println("            <p    class='dropdown-item' >Raw+Current</p>");
client.println("            <p    class='dropdown-item' >Enviorment</p>");
client.println("            <p    class='dropdown-item' >Gases</p>");
client.println("          </div>");
client.println("        </div>");
client.println("            <br>");
 
client.println("          <table class='table table-fluid '>");
client.println("              <thead>");
client.println("                <tr>");
client.println("                  <th scope='col'></th>");
client.println("                  <th scope='col'>Value Title</th>");
client.println("                  <th scope='col'>Sensor Value</th>");
 
client.println("                </tr>");
  
client.println("              </thead>");
client.println("              <tbody>");
 
client.println("                <tr id='1'>");
 
client.println("                  <td> ");   
client.println("                      <div class='sio5'>");
client.println("                          <svg enable-background='new 0 0 19.438 54.003'  id=Layer_1 version=1.1 viewBox='0 0 19.438 54.003'   xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M11.976,8.82v-2h4.084V6.063C16.06,2.715,13.345,0,9.996,0H9.313C5.965,0,3.252,2.715,3.252,6.063v30.982");
client.println("                          C1.261,38.825,0,41.403,0,44.286c0,5.367,4.351,9.718,9.719,9.718c5.368,0,9.719-4.351,9.719-9.718");
client.println("                          c0-2.943-1.312-5.574-3.378-7.355V18.436h-3.914v-2h3.914v-2.808h-4.084v-2h4.084V8.82H11.976z M15.302,44.833");
client.println("                          c0,3.083-2.5,5.583-5.583,5.583s-5.583-2.5-5.583-5.583c0-2.279,1.368-4.236,3.326-5.104V24.257C7.462,23.01,8.472,22,9.719,22");
client.println("                          s2.257,1.01,2.257,2.257V39.73C13.934,40.597,15.302,42.554,15.302,44.833z'fill=#F29C21 /></g></svg>");
client.println("                          </div>");
client.println("                  </td>");
client.println("                  <td class='tdc'>Raw Temperature </td>");
  
client.println("                  <td class='tdc'> ptr +=(float)rawTemperature;  <span >&deg;C</span></td>");
               
client.println("              </tr>");
  
client.println("                <tr id='2'>");
                
client.println("                  <td>    <div class='sio4'>");
client.println("                      <svg enable-background='new 0 0 29.235 40.64' id=Layer_1 version=1.1 viewBox='0 0 29.235 40.64' xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><path d='M14.618,0C14.618,0,0,17.95,0,26.022C0,34.096,6.544,40.64,14.618,40.64s14.617-6.544,14.617-14.617");
client.println("                      C29.235,17.95,14.618,0,14.618,0z M13.667,37.135c-5.604,0-10.162-4.56-10.162-10.162c0-0.787,0.638-1.426,1.426-1.426");
client.println("                      c0.787,0,1.425,0.639,1.425,1.426c0,4.031,3.28,7.312,7.311,7.312c0.787,0,1.425,0.638,1.425,1.425");
client.println("                      C15.093,36.497,14.455,37.135,13.667,37.135z'fill=#26B999 /></svg>");
client.println("                      </div>  </td>");
client.println("                  <td>Raw Humidity</td>");
client.println("                  <td> ptr +=(float)rawHumidity; <span> %</span></td>");
                 
client.println("                </tr>");
 
client.println("                <tr id='3'>");
               
client.println("                  <td>    <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 40.542 40.541' id=Layer_1 version=1.1 viewBox='0 0 40.542 40.541'xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M34.313,20.271c0-0.552,0.447-1,1-1h5.178c-0.236-4.841-2.163-9.228-5.214-12.593l-3.425,3.424");
client.println("                      c-0.195,0.195-0.451,0.293-0.707,0.293s-0.512-0.098-0.707-0.293c-0.391-0.391-0.391-1.023,0-1.414l3.425-3.424");
client.println("                      c-3.375-3.059-7.776-4.987-12.634-5.215c0.015,0.067,0.041,0.13,0.041,0.202v4.687c0,0.552-0.447,1-1,1s-1-0.448-1-1V0.25");
client.println("                      c0-0.071,0.026-0.134,0.041-0.202C14.39,0.279,9.936,2.256,6.544,5.385l3.576,3.577c0.391,0.391,0.391,1.024,0,1.414");
client.println("                      c-0.195,0.195-0.451,0.293-0.707,0.293s-0.512-0.098-0.707-0.293L5.142,6.812c-2.98,3.348-4.858,7.682-5.092,12.459h4.804");
client.println("                      c0.552,0,1,0.448,1,1s-0.448,1-1,1H0.05c0.525,10.728,9.362,19.271,20.22,19.271c10.857,0,19.696-8.543,20.22-19.271h-5.178");
client.println("                      C34.76,21.271,34.313,20.823,34.313,20.271z M23.084,22.037c-0.559,1.561-2.274,2.372-3.833,1.814");
client.println("                      c-1.561-0.557-2.373-2.272-1.815-3.833c0.372-1.041,1.263-1.737,2.277-1.928L25.2,7.202L22.497,19.05");
client.println("                      C23.196,19.843,23.464,20.973,23.084,22.037z'fill=#3C97D3  /></g></svg>");
client.println("                      </div> </td>");
client.println("                  <td>Pressure</td>");
client.println("                  <td>ptr +=(float)pressure; <span> hPa </span> </td>");
client.println("                </tr>");
  
client.println("                <tr id='4'>");
                 
client.println("                  <td>    <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 58.422 40.639' id=Layer_1 version=1.1 viewBox='0 0 58.422 40.639'  xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M58.203,37.754l0.007-0.004L42.09,9.935l-0.001,0.001c-0.356-0.543-0.969-0.902-1.667-0.902");
client.println("                      c-0.655,0-1.231,0.32-1.595,0.808l-0.011-0.007l-0.039,0.067c-0.021,0.03-0.035,0.063-0.054,0.094L22.78,37.692l0.008,0.004");
client.println("                      c-0.149,0.28-0.242,0.594-0.242,0.934c0,1.102,0.894,1.995,1.994,1.995v0.015h31.888c1.101,0,1.994-0.893,1.994-1.994");
client.println("                      C58.422,38.323,58.339,38.024,58.203,37.754z'fill=#955BA5 /><path d='M19.704,38.674l-0.013-0.004l13.544-23.522L25.13,1.156l-0.002,0.001C24.671,0.459,23.885,0,22.985,0");
client.println("                      c-0.84,0-1.582,0.41-2.051,1.038l-0.016-0.01L20.87,1.114c-0.025,0.039-0.046,0.082-0.068,0.124L0.299,36.851l0.013,0.004");
client.println("                      C0.117,37.215,0,37.62,0,38.059c0,1.412,1.147,2.565,2.565,2.565v0.015h16.989c-0.091-0.256-0.149-0.526-0.149-0.813");
client.println("                      C19.405,39.407,19.518,39.019,19.704,38.674z'fill=#955BA5 /></g></svg>");
client.println("                      </div></td>");
client.println("                  <td> <abbr title='Indoor air quality'>IAQ</abbr> </td>");
client.println("                  <td> ptr +=(float)iaq; <span> %</span> </td>");
client.println("                </tr>");
 
client.println("                <tr id='5'>");
                  
client.println("                  <td>  <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 58.422 40.639' id=Layer_1 version=1.1 viewBox='0 0 58.422 40.639' x=0px xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M58.203,37.754l0.007-0.004L42.09,9.935l-0.001,0.001c-0.356-0.543-0.969-0.902-1.667-0.902");
client.println("                      c-0.655,0-1.231,0.32-1.595,0.808l-0.011-0.007l-0.039,0.067c-0.021,0.03-0.035,0.063-0.054,0.094L22.78,37.692l0.008,0.004");
client.println("                      c-0.149,0.28-0.242,0.594-0.242,0.934c0,1.102,0.894,1.995,1.994,1.995v0.015h31.888c1.101,0,1.994-0.893,1.994-1.994");
client.println("                      C58.422,38.323,58.339,38.024,58.203,37.754z'fill=#D41515 /><path d='M19.704,38.674l-0.013-0.004l13.544-23.522L25.13,1.156l-0.002,0.001C24.671,0.459,23.885,0,22.985,0");
client.println("                      c-0.84,0-1.582,0.41-2.051,1.038l-0.016-0.01L20.87,1.114c-0.025,0.039-0.046,0.082-0.068,0.124L0.299,36.851l0.013,0.004");
client.println("                      C0.117,37.215,0,37.62,0,38.059c0,1.412,1.147,2.565,2.565,2.565v0.015h16.989c-0.091-0.256-0.149-0.526-0.149-0.813");
client.println("                      C19.405,39.407,19.518,39.019,19.704,38.674z'fill=#B02727 /></g></svg>");
client.println("                      </div> </td>");
client.println("                  <td> Gas Resistance </td>");
client.println("                  <td>  ptr +=(float)gasResistance; <span>k</span> </td>");
client.println("                </tr>");

client.println("                <tr id='6'>");
               
client.println("                  <td>     <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 58.422 40.639' id=Layer_1 version=1.1 viewBox='0 0 58.422 40.639' xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M58.203,37.754l0.007-0.004L42.09,9.935l-0.001,0.001c-0.356-0.543-0.969-0.902-1.667-0.902");
client.println("                      c-0.655,0-1.231,0.32-1.595,0.808l-0.011-0.007l-0.039,0.067c-0.021,0.03-0.035,0.063-0.054,0.094L22.78,37.692l0.008,0.004");
client.println("                      c-0.149,0.28-0.242,0.594-0.242,0.934c0,1.102,0.894,1.995,1.994,1.995v0.015h31.888c1.101,0,1.994-0.893,1.994-1.994");
client.println("                      C58.422,38.323,58.339,38.024,58.203,37.754z'fill=#955BA5 /><path d='M19.704,38.674l-0.013-0.004l13.544-23.522L25.13,1.156l-0.002,0.001C24.671,0.459,23.885,0,22.985,0");
client.println("                      c-0.84,0-1.582,0.41-2.051,1.038l-0.016-0.01L20.87,1.114c-0.025,0.039-0.046,0.082-0.068,0.124L0.299,36.851l0.013,0.004");
client.println("                      C0.117,37.215,0,37.62,0,38.059c0,1.412,1.147,2.565,2.565,2.565v0.015h16.989c-0.091-0.256-0.149-0.526-0.149-0.813");
client.println("                      C19.405,39.407,19.518,39.019,19.704,38.674z'fill=#955BA5 /></g></svg>");
client.println("                      </div></td>");
client.println("                  <td> <abbr title='Indoor Air quality'>IAQ</abbr> accuracy </td>");
client.println("                  <td> ptr +=(float)iaqAccuracy; <span> %</span></td>");
client.println("                </tr>");
client.println("                <tr id='7'>");
             
client.println("                  <td>     <div class='sio5'>");
client.println("                      <svg enable-background='new 0 0 19.438 54.003' id=Layer_1 version=1.1 viewBox='0 0 19.438 54.003' xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M11.976,8.82v-2h4.084V6.063C16.06,2.715,13.345,0,9.996,0H9.313C5.965,0,3.252,2.715,3.252,6.063v30.982");
client.println("                      C1.261,38.825,0,41.403,0,44.286c0,5.367,4.351,9.718,9.719,9.718c5.368,0,9.719-4.351,9.719-9.718");
client.println("                      c0-2.943-1.312-5.574-3.378-7.355V18.436h-3.914v-2h3.914v-2.808h-4.084v-2h4.084V8.82H11.976z M15.302,44.833");
client.println("                      c0,3.083-2.5,5.583-5.583,5.583s-5.583-2.5-5.583-5.583c0-2.279,1.368-4.236,3.326-5.104V24.257C7.462,23.01,8.472,22,9.719,22");
client.println("                      s2.257,1.01,2.257,2.257V39.73C13.934,40.597,15.302,42.554,15.302,44.833z'fill=#F29C21 /></g></svg>");
client.println("                      </div></td>");
client.println("                  <td> Temperature </td>");
client.println("                  <td>ptr +=(float)temperature; <span>&deg;C</span> </td>");
client.println("                </tr>");
 
client.println("                <tr id='8'>");
            
client.println("                  <td>    <div class='sio4'>");
client.println("                      <svg enable-background='new 0 0 29.235 40.64' id=Layer_1 version=1.1 viewBox='0 0 29.235 40.64'  xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><path d='M14.618,0C14.618,0,0,17.95,0,26.022C0,34.096,6.544,40.64,14.618,40.64s14.617-6.544,14.617-14.617");
client.println("                      C29.235,17.95,14.618,0,14.618,0z M13.667,37.135c-5.604,0-10.162-4.56-10.162-10.162c0-0.787,0.638-1.426,1.426-1.426");
client.println("                      c0.787,0,1.425,0.639,1.425,1.426c0,4.031,3.28,7.312,7.311,7.312c0.787,0,1.425,0.638,1.425,1.425");
client.println("                      C15.093,36.497,14.455,37.135,13.667,37.135z'fill=#26B99A /></svg>");
client.println("                      </div> </td>");
client.println("                  <td>Humidity</td>");
client.println("                  <td> ptr +=(float)humidity; <span>%</span> </td>");
client.println("                </tr>");
 
client.println("                <tr id='9'>");
               
client.println("                  <td>  <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 58.422 40.639' id=Layer_1 version=1.1 viewBox='0 0 58.422 40.639' xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M58.203,37.754l0.007-0.004L42.09,9.935l-0.001,0.001c-0.356-0.543-0.969-0.902-1.667-0.902");
client.println("                      c-0.655,0-1.231,0.32-1.595,0.808l-0.011-0.007l-0.039,0.067c-0.021,0.03-0.035,0.063-0.054,0.094L22.78,37.692l0.008,0.004");
client.println("                      c-0.149,0.28-0.242,0.594-0.242,0.934c0,1.102,0.894,1.995,1.994,1.995v0.015h31.888c1.101,0,1.994-0.893,1.994-1.994");
client.println("                      C58.422,38.323,58.339,38.024,58.203,37.754z'fill=#955BA5 /><path d='M19.704,38.674l-0.013-0.004l13.544-23.522L25.13,1.156l-0.002,0.001C24.671,0.459,23.885,0,22.985,0");
client.println("                      c-0.84,0-1.582,0.41-2.051,1.038l-0.016-0.01L20.87,1.114c-0.025,0.039-0.046,0.082-0.068,0.124L0.299,36.851l0.013,0.004");
client.println("                      C0.117,37.215,0,37.62,0,38.059c0,1.412,1.147,2.565,2.565,2.565v0.015h16.989c-0.091-0.256-0.149-0.526-0.149-0.813");
client.println("                      C19.405,39.407,19.518,39.019,19.704,38.674z'fill=#955BA5 /></g></svg>");
client.println("                      </div></td>");
client.println("                  <td>Static  <abbr title='Indoor air quality'>IAQ</abbr> </td>");
client.println("                  <td>  ptr +=(float)staticIaq; <span> %</span> </td>");
client.println("                </tr>");
 
client.println("                <tr id='10'>");
               
client.println("                  <td>  <div class='sio'>");
client.println("                      <svg enable-background='new 0 0 19.438 54.003'height=54.003px id=Layer_1 version=1.1 viewBox='0 0 19.438 54.003'width=19.438px x=0px xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><g><path d='M11.976,8.82v-2h4.084V6.063C16.06,2.715,13.345,0,9.996,0H9.313C5.965,0,3.252,2.715,3.252,6.063v30.982");
client.println("                      ptr += 'C1.261,38.825,0,41.403,0,44.286c0,5.367,4.351,9.718,9.719,9.718c5.368,0,9.719-4.351,9.719-9.718");
client.println("                      ptr += 'c0-2.943-1.312-5.574-3.378-7.355V18.436h-3.914v-2h3.914v-2.808h-4.084v-2h4.084V8.82H11.976z M15.302,44.833");
client.println("                      ptr += 'c0,3.083-2.5,5.583-5.583,5.583s-5.583-2.5-5.583-5.583c0-2.279,1.368-4.236,3.326-5.104V24.257C7.462,23.01,8.472,22,9.719,22");
client.println("                      ptr += 's2.257,1.01,2.257,2.257V39.73C13.934,40.597,15.302,42.554,15.302,44.833z'fill=#808080 /></g></svg>");
client.println("                      </div></td>");
client.println("                  <td>CO2 Equivalent</td>");
client.println("                  <td>ptr +=(float)co2Equivalent; <span> ppm</span> </td>");
client.println("                </tr>");
      
client.println("                <tr id='11'>");
             
client.println("                  <td>   <div class='sio4'>");
client.println("                      <svg enable-background='new 0 0 29.235 40.64'id=Layer_1 version=1.1 viewBox='0 0 29.235 40.64'  xml:space=preserve xmlns=http://www.w3.org/2000/svg xmlns:xlink=http://www.w3.org/1999/xlink y=0px><path d='M14.618,0C14.618,0,0,17.95,0,26.022C0,34.096,6.544,40.64,14.618,40.64s14.617-6.544,14.617-14.617");
client.println("                      C29.235,17.95,14.618,0,14.618,0z M13.667,37.135c-5.604,0-10.162-4.56-10.162-10.162c0-0.787,0.638-1.426,1.426-1.426");
client.println("                      c0.787,0,1.425,0.639,1.425,1.426c0,4.031,3.28,7.312,7.311,7.312c0.787,0,1.425,0.638,1.425,1.425");
client.println("                      C15.093,36.497,14.455,37.135,13.667,37.135z'fill=#008000 /></svg>");
client.println("                      </div></td>");
client.println("                  <td>Breath <abbr title='volatile organic compounds'>VOC</abbr> Equivalent  </td>");
client.println("                  <td> ptr +=(float)breathVocEquivalent; <span> ppm</span></td>");
client.println("                </tr>");

client.println("                <tr>");
 
client.println("                  <td> </td>");
client.println("                  <td> </td>");
client.println("                  <td> </td>");
client.println("                </tr>");
 
client.println("              </tbody>");
client.println("            </table>");
 
client.println("      </div>");
 
client.println("       </div>");
 
client.println("      </div>");
 
client.println("      <!--Table end FUD End-->");
 
client.println("      <footer class='footer-copyright text-center py-3'>");
client.println("          <marquee>Project By M.Ibrahim, Dr. Khurrum Shahzad Quraishi(PIEAS), Dr Maryam Zaffar, HTML By M Talha Khalid</marquee>");
client.println("      </footer>");
  
client.println("  <script>");
client.println("    $('.dropdown-item').on('click',  function(){");
client.println("          var btnObj = $(this).parent().siblings('button');");
client.println("          $(btnObj).text($(this).text();");
client.println("          $(btnObj).val($(this).text();");
client.println("           if(btnObj.text()=='Current Sensor Values'){");
client.println("             $('#1').hide();");
client.println("             $('#2').hide();");
client.println("             $('#3').show();");
client.println("             $('#4').show();");
client.println("             $('#5').show();");
client.println("             $('#6').hide();");
client.println("             $('#7').show();");
client.println("             $('#8').show();");
client.println("             $('#9').show();");
client.println("             $('#10').show();");
client.println("             $('#11').show();");
client.println("           }");
client.println("           if(btnObj.text()=='Raw+Current') {");
client.println("            $('#1').show();");
client.println("             $('#2').show();");
client.println("             $('#3').show();");
client.println("             $('#4').show();");
client.println("             $('#5').show();");
client.println("             $('#6').show();");
client.println("             $('#7').show();");
client.println("             $('#8').show();");
client.println("             $('#9').show();");
client.println("             $('#10').show();");
client.println("             $('#11').show();");
client.println("           }");
 
client.println("           if(btnObj.text()=='Enviorment') {");
client.println("            $('#1').hide();");
client.println("             $('#2').hide();");
client.println("             $('#3').show();");
client.println("             $('#4').hide();");
client.println("             $('#5').show();");
client.println("             $('#6').hide();");
client.println("             $('#7').show();");
client.println("             $('#8').show();");
client.println("             $('#9').hide();");
client.println("             $('#10').show();");
client.println("             $('#11').show();");
client.println("           }");
 
client.println("           if(btnObj.text()=='Gases') {");
client.println("            $('#1').hide();");
client.println("             $('#2').hide();");
client.println("             $('#3').show();");
client.println("             $('#4').hide();");
client.println("             $('#5').show();");
client.println("             $('#6').hide();");
client.println("             $('#7').hide();");
client.println("             $('#8').hide();");
client.println("             $('#9').hide();");
client.println("             $('#10').show();");
client.println("             $('#11').show();");
client.println("           }");
client.println("      });");
 
 
client.println("  </script>");
 
client.println("      </body>");
 
client.println("      </html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}