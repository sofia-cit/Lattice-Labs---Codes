void WaitConnection()
{
  while(!client.connected())
  {
    client=server.available();
    Serial.println("Esperando conexion con el cliente");
    delay(1000);
  }
}