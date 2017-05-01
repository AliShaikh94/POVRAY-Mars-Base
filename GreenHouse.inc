#include "Tree.inc"
#declare GreenHouse =
union {
    #declare Length = 4.2;
    #declare Width = 1.5;
    cylinder {<0,0,-Length+.4>, <0,0,Length-.4>, Width
        material{   //-----------------------------------------------------------
        texture { pigment{ rgbf <0.98, 0.98, 0.98, 0.9> }
                  finish { diffuse 0.1 reflection 0.2  
                          specular 0.8 roughness 0.0003 phong 1 phong_size 400}
                } // end of texture -------------------------------------------
        interior{ ior 1.5 caustics 0.5
                } // end of interior ------------------------------------------
      } // end of material ----------------------------------------------------
       translate<0,0.00, -2.6>

    }
    #local Rows = 0;
    #while(Rows<7)
        object{ Tree_00 
            scale <1,1,1>*.25
            // rotate<0,30,0> 
            translate<0.5,0.00, -Rows>
        }
        object{ Tree_00 
        scale <1,1,1>*.25
        // rotate<0,30,0> 
        translate<-.4,0.00, -Rows>
        }
        #local Rows = Rows+1;
    #end
    union {
        #declare LiquidLevelTop = .2;
        #declare LiquidLevelBottom = 0;
        box {<0.2,LiquidLevelBottom,0.2>, <-0.2,LiquidLevelTop,-6.2>}
        texture{pigment { rgb <0.2, 0.2, 0.2> } 
        normal { bozo 1.75 
                 turbulence 0.9 translate<0,0,-2>}
        finish { ambient 0.15 diffuse 0.65 
                 brilliance 6.0 phong 0.8 phong_size 120
                 reflection 0.6}
        scale <2.0,1,0.3>*0.20  rotate<0,10,0>
        }
        // translate<0,0.00,-1>
        // scale <0,0,20>

    }
    translate<0,0.00, 2.6>
}

// object{
//     GreenHouse //scale 1/6
// }
// merge {
//     object{GreenHouse }
//     object{GreenHouse  translate <-3.6,0,0> rotate y*90 scale x*1.5}
// }