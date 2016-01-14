#include <ESP8266WiFi.h>

const char* ssid = "Making Sense Guest II";
const char* password = "Formosa278";

int t = 0;  // TEMPERATURE VAR
String data;
String content; // contador de listas
int cont =0;

WiFiClient client;

void setup() {

  pinMode(2, INPUT); 
  
  // iniciando conexi�n...
  Serial.begin(115200);
  Serial.println("Conectando a: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Conectado a Red WI-FI");
    Serial.println(ssid);
    Serial.print("La Ip de la placa es: ");
    Serial.println(WiFi.localIP());

    data = "";
    content="";
}

void loop() 
{  
 //if(cont < 10)
 //{
  //data = String("'name':" + cont);
    data = "{'name': 'test4'}";
    //data = "{'name': 'test'}";
    if(client.connect("newapiint.fromdoppler.net",80)) 
    { 
      client.println("POST /accounts/api_functionaltests@mailinator.com/lists?api_key=22495B800297B754C6EF66FA2C5C1902 HTTP/1.1");
      client.println("Host: newapiint.fromdoppler.net");
      client.println("Content-Type: application/json");
      client.print("Content-Length: ");
      client.println(data.length());
      client.println(); 
      client.println(data); 
      Serial.print(" Datos enviados " + data);
      delay(3000);      
    }
    else 
    {
    Serial.println("#Fallo en la conexion");
    }
  //  cont++;
// }
}
