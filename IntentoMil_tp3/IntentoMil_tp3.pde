//Alumna: Tatiana Dulce Itatí Segundo
//___________________
//Preguntar efecto dif. de color
//Preguntar por "latido" del centro
int num;
float rMap;

void setup() { 
  size(700, 900);
  background(0);
  ellipseMode(CENTER);
  colorMode(HSB, 360, 100, 100);
  num = 1;
  smooth();
}
void draw() {
 //Insertar código para la puerta(faltan detalles)
 //Área provisoria p/ visibilizar botón(picaporte)
 noStroke();
 fill(255);
 circle(600,450,100);
  if (dist(mouseX, mouseY, 600, height/2)<50) {
    for (int i = 2000; i > 0; i-=2000/num) {
      noStroke();
      for ( int iRell = 0; iRell < 10; iRell++) {
        rMap = map(iRell*i/5, 0, 2000, 0, 1);
        color inicio = color(249, 99, 99);
        color fin = color(321, 99, 97);
        fill(lerpColor(inicio, fin, rMap));
        circle(width/2, height/2-80, i-iRell*4);

        if (key == 'a') {
          fill(lerpColor(fin, inicio, rMap));
          circle(width/2, height/2-80, i-iRell*4);
        } else if ( key == 'b') {
          fill(lerpColor(color(360, 99, 99), color(249, 99, 99), rMap));
          circle(width/2, height/2-80, i-iRell*4);
        }
      }
    }
    num++;
  }
}
void keyPressed() {
  if (key== 'r') {

    rMap = 0;
    num =1;
  }
}
