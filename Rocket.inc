#macro Rocket()
#include "Flame.inc"

#declare Engine =
 union{

   cone{<0,0,0>,0.5,
    <0,1.5,0>,0.25
    scale<1,1,0.7>
    translate<0,0.5,0>
    texture{Chrome_Metal}}
    prism { -0.01 ,0.01 , 4
      <0.0,0.0>,<0.8,0>,
      <0.0,1.5>,<0.0,0>
      rotate<-90,0,0>
      translate<0,0.5,0>
      texture{pigment{color White }
      finish{ diffuse 0.9
        phong 1}
      }
    }// end of prism
   difference{
    cone{<0, 0.10,0>,0.28,
     <0,0.50,0>,0.10}
     cone{<0, 0.09,0>,0.17,
       <0,0.49,0>,0.09}
       translate<0.22,0,0>
       texture{Chrome_Metal}
     }
           object{
      F_T_Fire()  scale .3
      translate<0,0,0>}


     // Ali: Using the flame thrower flame here 
       translate<.25,0,0>
  }
//------ building  the rocket -----
union{//4 engines
   object{Engine rotate<0,  0,0>}
   object{Engine rotate<0, 90,0>}
   object{Engine rotate<0,180,0>}
   object{Engine rotate<0,270,0>}

//----- the body ------------------
   cylinder{<0,0,0>,<0,5,0>,0.5
     translate<0,0.5,0>
     texture{
      pigment{color White}
      finish {diffuse 0.9
        phong 1}}}
// ----- with some details --------
        cylinder{<0,0,0>,<0,0.1,0>,0.50
         translate<0,2.0,0>
         texture{Chrome_Metal}}
         cylinder{<0,0,0>,<0,0.1,0>,0.50
           translate<0,3.5,0>
           texture{Chrome_Metal}}
           cylinder{<0,0,0>,<0,0.1,0>,0.50
             translate<0,5.25,0>
             texture{Chrome_Metal}}
//------- the top part ------------
             cone {<0,0,0>,0.5,<0,1.5,0>,0.25
               translate<0,5.5,0>
               texture{Chrome_Metal}}
//--- the nose on top of the rocket
               sphere {<0,0,0>,0.25 scale<1,1.5,1>
                 translate<0,5.0+1.5+0.5,0>
                 texture{Chrome_Metal}}
}//--end of union -----------------


#end // end of macro 