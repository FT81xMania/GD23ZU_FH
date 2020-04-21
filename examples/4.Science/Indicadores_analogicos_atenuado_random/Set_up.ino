void setup() {
  GD.begin();
  //GD.wr(REG_PWM_DUTY, 75);  //0-128  intensidad de la retroiluminación XD

  espera();          
  carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b
 // MP();  //con iconos    ---solo iconos en incremento de tamaño
  MP1();  //sin iconos   -----atenuado
 // MP3();  //sin iconos -----sin atenuar
}
void loop(){}
