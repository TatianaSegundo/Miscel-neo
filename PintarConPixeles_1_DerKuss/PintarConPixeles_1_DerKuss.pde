PImage derKuss;

void setup() {
  size(900, 900);
  derKuss=loadImage("derkussklimt.jpg");
  background(0);
}

void draw() {
float x = random(width);
float y = random(height);
color c = derKuss.get(int(x),int(y));
noStroke();
fill(c);
  ellipse(x, y, 16, 16);
}
