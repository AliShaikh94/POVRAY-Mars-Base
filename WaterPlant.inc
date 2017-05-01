#include "stones.inc"

#declare WaterPlant =
union {
   #declare DishHeight = 1;
   #declare Radius = 4.2;
   difference {
      cylinder {<0,DishHeight-1,0>, <0,DishHeight,0>, Radius}
      // sphere{ <0,2.4,0>, 4.2 }
      cylinder {<0,DishHeight-1+.1,0>, <0,DishHeight+.2,0>, Radius-.4}
   }

   // difference {
   //    cylinder {<0,0.2,0>, <0,2.5,0>, 4}
   //    torus {2.8, 1 translate y*2.5}
   //    torus {4, 1 translate y*0}
   //    cylinder {<0,1.5,0>, <0,2.6,0>, 2.8}
   // }

   union {
      #declare LiquidLevelTop = DishHeight-0.2;
      #declare LiquidLevelBottom = DishHeight-1;
      cylinder {<0,LiquidLevelBottom,0>, <0,LiquidLevelTop,0>, Radius-.2}
      // torus {3.6, 0.2 translate y*LiquidLevelTop}
      // cylinder {<0,LiquidLevelTop-0.2,0>,<0,LiquidLevelTop+0.3,0>,3.6}
      // pigment {Orange*0.8 filter 0.6}
      // finish {phong 0.7 reflection 0.15}
      // normal {bumps 0.05 scale 1}
      texture{pigment { rgb <0.2, 0.2, 0.2> } 
        normal { bozo 1.75 
                 turbulence 0.9 translate<0,0,-2>}
        finish { ambient 0.15 diffuse 0.65 
                 brilliance 6.0 phong 0.8 phong_size 120
                 reflection 0.6}
        scale <2.0,1,0.3>*0.20  rotate<0,10,0>
       }
   }

   torus {4.0, 0.2 translate y*1.0 texture{Chrome_Metal}}
   torus {4.39, 1 translate y*0.0 
       texture{ T_Stone43    
                //normal { agate 0.25 scale 0.25 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 0.5 translate<0,0,0>
              } // end of texture 
   } // end of texture ---------------------------}
   union { // This is the middle control arm 
        cylinder {<0,1.2,-Radius+.4>, <0,1.2,Radius-.4>, .2}
        // Gearbox thing?
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

          texture { pigment{ color Black}  
                    finish { phong 1 reflection 0.00}
                  } // end of texture

          scale <.5,.5,1> rotate<0,0,0> translate<0,.5,0> 
        } // end of box --------------------------------------
   }
   sphere{ <0,1,0>, Radius
        texture { pigment{ color rgbt<1,1,1,0.7>}
                  finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                } // end of texture
        scale <1,.5,1> rotate<0,0,0> // translate<0,0.25,0>
      } // end of torus  -------------------------------  
   // torus {4.0, 0.2 translate y*1.2}
   // torus {2.8, 0.2 translate y*0.2}

   // union {
   //    difference {
   //       cylinder {<0.2,0,0>,<-0.2,0,0>,0.5}
   //       torus {0.5, 0.2 rotate z*90 translate x*0.2}
   //       translate y*1.25
   //    }
   //    difference {
   //       cylinder {<0.2,0,0>,<-0.2,0,0>,0.5}
   //       torus {0.5, 0.2 rotate z*90 translate x*0.2}
   //       translate y*-1.25
   //    }
   //    torus {1.25, 0.3 rotate x*90 clipped_by {plane {x,0 inverse}} translate x*0.8}
   //    cylinder {<0,-1.25,0>,<0.8,-1.25,0>,0.3}
   //    cylinder {<0,1.25,0>,<0.8,1.25,0>,0.3}
   //    scale <1,1,1.5> translate <4.2,4,0> rotate y*-90
   // }

   pigment {White}
   normal {bumps 0.05 scale 3}
   finish {phong 0.8 reflection 0.1}
}

