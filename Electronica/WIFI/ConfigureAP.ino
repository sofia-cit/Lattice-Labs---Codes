void ConfigureAP()
{
  IPAddress IP_AP(192, 168, 4, 1);
  IPAddress subnet(255, 255, 255, 0);

  WiFi.softAPConfig(IP_AP, IP_AP, subnet);
  WiFi.softAP(ssid, password);

  Serial.println("Punto de acceso configurado");
  Serial.print("Direccion del punto de acceso: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}