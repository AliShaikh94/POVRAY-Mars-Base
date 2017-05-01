// POV-Ray 3.6/3.7 Scene File "Minimal.pov"
// by Friedrich A. Lohmueller, Jan-2013
//-------------------------------------------
#version 3.7;
global_settings { assumed_gamma 2.2 max_trace_level 5 }
// #default{ finish{ ambient 0.1 diffuse 0.9 }}
//------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "functions.inc"
#include "Rocket.inc"
#include "WaterPlant.inc"
#include "GreenHouse.inc"

#include "metals.inc"



#include "Mast.inc" 
//------------------------------------------
// camera ----------------------------------  
#declare Camera_0 = // This is the closeup!  
camera
{
    location<-1, 5,-8>
    look_at<1,0, 0.0>
    //look_at<.5,1, 0.0>
    right x* image_width / image_height
    angle 75
}                                           
#declare Camera_1 = // This is the Full Shot! 
camera
{
    location<-5, 3,-8>
   right x*image_width/image_height // keep propotions with any aspect ratio  
   angle 75
   look_at <0.0, 2.0, -2.0>
}   
camera{Camera_1}
// sun -------------------------------------
// light_source { <1500, 3000, -2500> color White }
light_source { <1500, 3000, 2500> color White }
// sky -------------------------------------

// plane{ <0,1,0>,1 hollow
//  texture{
//    pigment{ bozo turbulence 0.92
//      color_map{
//        [0.00 rgb<0.05,0.15,0.45>]
//        [0.50 rgb<0.05,0.15,0.45>]
//        [0.70 rgb<1,1,1>        ]
//        [0.85 rgb<0.2,0.2,0.2>  ]
//        [1.00 rgb<0.5,0.5,0.5>  ]
//                      } //
//                      scale<1,1,1.5>*2.5
//                      translate<0,0,0>
//          } // end of pigment
//          finish {ambient 1 diffuse 0}
//       } // end of texture
//       scale 10000}

// sky ----------------------------------
sky_sphere
{
    pigment
    {
        gradient<0, 1, 0>
            color_map
        {
            [0.00 color rgb<251, 194, 106> / 256]
                [0.50 color rgb<240, 170, 98> / 256]
                [1.00 color rgb<208, 138, 76> / 256]
            // [0.23 color rgb<0.16,0.32,0.9> *0.9]
            // [0.37 color rgb<1,0.1,0> ]
            // [0.52 color rgb<1,0.2,0> ]
            // [0.70 color rgb<0.36,0.32,1> *0.7 ]
            // [0.80 color rgb<0.14,0.32,1> *0.5 ]
            // [1.00 color rgb<0.24,0.32,1> *0.3 ]
        } // end color_map
        scale 2 rotate<-20, 0, 0>
            translate<0, 0.7, 0>
    } // end pigment
}

#declare Mast_Texture = 
 texture { //Chrome_Metal}  
           pigment{ color rgb<1,1,1> } 
           finish { phong 0.1} 
         } // end of texture
#declare Base_Texture =
 texture{ pigment{ color rgb<1,1,1>*0.7}
          finish { phong 1}
        } // end of texture // end sky_sphere ---------------------
        

#declare HF_Res_X = 1024; // number of points in x
#declare HF_Res_Z = 1024; // number of points in z
#declare SF =
function
{
    pigment
    {
        spherical
            color_map
        {
            [ 0.0, color 0.0 ]
                [0.5, color 0.8]
                [1.0, color 1.0]
        } // end color_map
        scale<0.5, 1, 0.5>
            translate<0.5, 0, 0.5>
    } // end pigment
} // end function

#declare HF_Function =
function(x, y, z)
{
    1 + f_snoise3d(x * 10, y * 10, z * 10) * 0.3 * SF(x, y, z).gray
}

#declare HF_Amplitude = 0.5;
#declare D = 0.00001; // just a little bit!


#declare T_MarsMountainTex =
texture{
    pigment{
        gradient y
            color_map{
                    [.00 color rgb<178, 89, 46> / 256]
                    [.10 color rgb<178, 89, 46> / 256]
                    [1.0 color rgb<178, 89, 46> / 256]
                // [.10 color rgb<.8,  1,  1>]
                // [.20 color rgb<1,  1,  1>]
                // [.30 color rgb<1,  .9,  .7>]
                // [.40 color rgb<0,  .2,  0>]
                // [.60 color rgb<.2, .4,  .1>]
                // [.80 color rgb<.4, .2,  .0>]
                // [.93 color rgb<.3, .0,  .0>]
                // [.95 color rgb<.6, .2,  .1>]
                // [1.0 color rgb<.0,  0,   0>]
            } } finish{ diffuse 0.5 crand 0.01975 }
};     

#declare Terrain_Obj=
    height_field {
    function 1000  ,1000 {
      pigment {
        agate
        color_map {
          [0.0 color rgb 0.0]
          [0.3 color rgb 0.2]
          [0.7 color rgb 0.8]
          [1.0 color rgb 1.0]
        }
        warp { turbulence 0.01 }
        scale 5 
        //translate <1.8, -6.7, 0>
     
        //translate <3, 3, 0>
        scale 1/6
        
        //translate -0.5*y    
        scale <1, 0, 1>
        //translate 0.5*y
      } 
    }
    
    rotate -90*x
    scale <6, 6, -0.4>*2
    translate <-3, -3, 0>    
    rotate 90*x
    scale <2, 1, 2>
}

union {   
    
    plane
    {
        <0, 1, 0>, 0 texture
        {
            pigment { color rgb<178, 89, 46> / 256 }
            normal { bumps 0.3 scale 0.015 }
            finish { phong 0.1 }
        }
    }    
    /*   
    object{ 
    Terrain_Obj 
         texture
        {
            pigment { color rgb<178, 89, 46> / 256 }
            normal { bumps 0.3 scale 0.015 }
            finish { phong 0.1 }
        }} 
    */
    object{ 
Terrain_Obj
      clipped_by{plane{x,0}}
       clipped_by{plane{z,10}}
     texture
    {
        pigment { color rgb<178, 89, 46> / 256 }
        normal { bumps 0.3 scale 0.015 }
        finish { phong 0.1 }
    }
    translate<-15,.75, 0> 
    } 
    height_field
    {
        png "terrain\\mt-taranaki.png" 
        //smooth
        texture{
             T_MarsMountainTex
             scale 2 
             translate<0, -1.0, 0>
         }
        /*texture 
        {
            pigment { color rgb<178, 89, 46> / 256 }
            normal { bumps 0.3 scale 0.015 }
            finish { phong 0.1 }
        }  */
        //rotate<0, -90, 0>
        scale<1, .35, 1>*10
        translate<-5, -0.1, -7>   
        //rotate y*100
        scale 3
    }
	
	rotate y*-90   
	translate<1.5,0,15>   
	

}
//------------------------------------------
//objects in scene ------------------------
//------------ ready for take off:   



 object{ 
 	WaterPlant
 	rotate y*125
 	scale 1/8
 	translate <-3, 0, -3>
 }
  object{ 
 	WaterPlant
 	rotate y*45
 	scale 1/8
 	translate <-2.76, 0, -1.7>
 }
// ----------------------------- end
// -----------------------------------------

  object{ 
 	merge {
	    object{GreenHouse scale z*1.5}
	    object{GreenHouse  translate <-4.6,0,0> rotate y*90 scale x*1.5}
	}
 	// rotate y*45
 	 scale 1/4
 	 translate <-1.5, 0, -1.7>
 }
union {
object{ Mast_1(   8, // number of segments * segment height = total height 
                  2.00, // segment_height
                  1.00, // half width (outline!)
                  0.050,  // R1, tube main radius
                  0.025   // R2, tube diagonals radius 
                                 
                 ) //------------------------------------------------------------------//
        texture { Mast_Texture }
        scale <1,1,1>*1
        rotate<0,0,0> 
        translate<0.00,0.05, 0.00>}
//-------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------
// base:   
box {<-1,0,-5>,< 1,0.05,1>  texture{Base_Texture}}
	scale 1/4
	translate<5.5, .8, 0>
}

 object
 {
     Rocket()
     rotate<0, 0, 0>
     translate<18, 5, -3>
     scale .3
}
#include "station.inc";
object {station 
        // rotate <-25,10,-20>
        translate <.45, -.6, -1.5>
     	scale 3

    }
 light_source { <0,10,0>          
   color rgb <0.8, 0.5, 0.2>*1   
               area_light            // kind of light source (Art der Lichtquelle)
               <0, 0, 0> <0, 0.25, 0> // lights spread out across this distance 
               1, 10                // total number of lights in grid  
               adaptive 3          // 0,1,2,3...
               jitter              // adds random softening of light
               translate<0,0,0>
 } //---------------- end of area_light 
                  
