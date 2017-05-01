//space station object

//declare some variables
#version 3.0;
#declare or =0.8   //outer ring radius
#declare ir =0.8-.1//inner ring radius
#declare hr=0.1    //heigth of ring
#declare dr=0.131  //thickness of ring
#declare ha=0.73   //total height of station
#declare ra=0.073  //radius of axis cylinder
#declare rs=dr/4.5 //radius of spoke
#declare ls=or-dr/2//lenght of spoke
#declare hs=hr/2   //insert.of spoke
#declare rss=rs/7  //radius of small spoke
#declare tc=0.015  //thickness of 'under construction'
#declare rm=0.1168 //radius of main cylinder
#declare hm=0.146  //height of main cylinder
#declare hc=0.1    //height of cone 

//declare some parts of the station

//upper ring 
#declare upper_ring=
union{	
 difference{
  cylinder { <0,ha-hr,0>,<0,ha,0>,or}
  cylinder { <0,ha-hr-.1,0>,<0,ha+.1,0>,or-dr}}
 difference{
  cylinder { <0,ha-hr+.001,0>,<0,ha-.001,0>,or-.001
  texture {pigment { color red .9 green .9 blue .95 } finish { phong 1 } }}
  cylinder { <0,ha-hr-.1,0>,<0,ha+.1,0>,or-dr+.001}}
}

//lower ring
#declare lower_ring = union {
 cylinder { <0,0,0>,<0,hr,0>,or	   open } 
 cylinder { <0,0,0>,<0,hr,0>,or -dr open }
 disc { <0, 0,0>,<0,1,0>,or  or -dr }
 disc { <0,hr,0>,<0,1,0>,or  or -dr }}

//segments of lower ring
#declare ring_segment = union{

 object { lower_ring
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{-x,0} rotate y*10}
 clipped_by{plane{ x,0} rotate y*(-10)}}

 object{ lower_ring
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{-x,0} rotate y*(-10)}
 clipped_by{plane{ x,0} rotate y*10}}

 object{ lower_ring
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{ z,0} rotate y*(-10)}
 clipped_by{plane{-z,0} rotate y*10}}

 object{ lower_ring
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{ z,0} rotate y*10}
 clipped_by{plane{-z,0} rotate y*(-10)}}
}
//parts under construction
#declare construct=union {
							//outer
cylinder { <0, 0,0>,	<0,.1*hr,0>, or-.001	  open }
cylinder { <0,.2*hr,0>, <0,.3*hr,0>, or-.001	  open }
cylinder { <0,.4*hr,0>, <0,.55*hr,0>,or-.001	  open }
cylinder { <0,.65*hr,0>,<0,.77*hr,0>,or-.001	  open }
cylinder { <0,.85*hr,0>,<0,.95*hr,0>,or-.001	  open }
							//inner
cylinder { <0,.4*hr,0>, <0,.65*hr,0>,or -dr+.001 open }}

//assemble the space station with include files

#declare station= 
 object{ 
  union {

//upper ring
#include "upper.inc"
//scatter light sources in the ring
light_source { <0,ha-.5*hr,-or+.5*dr> color red 1  green 1  blue .5 }
light_source { <0,ha-.5*hr,-or+.5*dr> color red 1  green .7 blue 1   rotate y*20}
light_source { <0,ha-.5*hr,-or+.5*dr> color red 1  green .9 blue 0   rotate y*60}
light_source { <0,ha-.5*hr,-or+.5*dr> color red .8 green 1  blue 1   rotate y*100}
light_source { <0,ha-.5*hr,-or+.5*dr> color red .7 green .5 blue .7  rotate y*140}
light_source { <0,ha-.5*hr,-or+.5*dr> color red 1  green .9 blue .7  rotate y*180}
light_source { <0,ha-.5*hr,-or+.5*dr> color red .8 green .8 blue 1   rotate y*220}
light_source { <0,ha-.5*hr,-or+.5*dr> color red .8 green .8  blue .6  rotate y*260}
light_source { <0,ha-.5*hr,-or+.5*dr> color red 1  green .9 blue .7  rotate y*320}

//upper spokes

//thick
cylinder {<-ls,0,0>   <-rm*.9,0,0> rs open scale <1.,.6,1.> translate (ha-hs)*y}
cylinder {<rm*.9,0,0> <ls,0,0> rs open scale <1.,.6,1.> translate (ha-hs)*y}
cylinder {<0,0,-ls>   <0,0,-rm*.9> rs open scale <1.,.6,1.> translate (ha-hs)*y}
cylinder {<0,0,rm*.9> <0,0,ls> rs open scale <1.,.6,1.> translate (ha-hs)*y}

//thin
cylinder {<-ir,ha-hs/1.5,0><ir,ha-hs/1.5,0> rss open translate<0,0,rs*2.5>}
cylinder {<-ir,ha-hs/1.5,0><ir,ha-hs/1.5,0> rss open translate<0,0,-rs*2.5>}

cylinder {<-ir,ha-hs/1.5,0><ir,ha-hs/1.5,0> rss open translate<0,0,rs*1.7>}
cylinder {<-ir,ha-hs/1.5,0><ir,ha-hs/1.5,0> rss open translate<0,0,-rs*1.7>}


cylinder {<0,ha-hs/1.5,-ls><0,ha-hs/1.5,-rm*.9> rss open translate<-rs*2.5,0,0>}
cylinder {<0,ha-hs/1.5,rm*.9><0,ha-hs/1.5,ls>   rss open translate<-rs*2.5,0,0>}

cylinder {<0,ha-hs/1.5,-ls><0,ha-hs/1.5,-rm*.9> rss open translate<-rs*1.7,0,0>}
cylinder {<0,ha-hs/1.5,rm*.9><0,ha-hs/1.5,ls>   rss open translate<-rs*1.7,0,0>}


cylinder {<0,ha-hs/1.5,-ls>  <0,ha-hs/1.5,-rm*.9> rss open translate<rs*2.5,0,0>}
cylinder {<0,ha-hs/1.5,rm*.9><0,ha-hs/1.5,ls>     rss open translate<rs*2.5,0,0>}

cylinder {<0,ha-hs/1.5,-ls>  <0,ha-hs/1.5,-rm*.9> rss open translate<rs*1.7,0,0>}
cylinder {<0,ha-hs/1.5,rm*.9><0,ha-hs/1.5,ls>     rss open translate<rs*1.7,0,0>}



//upper part of axis with hangar
intersection{
 cylinder {<0,ha-hm,0><0,ha,0> rm}
 box{<-rm*.8,0,-rm*.2>,<rm*.8,hm,rm*.2> translate <0,ha-hm/2,0> inverse}
}
//lighten the hangar
light_source { <-rm*.4,ha-hm*.2,0>  color red .6 green .4 blue .4}
light_source { <0,ha-hm*.2,0> color red .6 green .1 blue .3}
light_source { <rm*.4,ha-hm*.2,0> color red .6 green .3 blue .3}

//lower ring
object {ring_segment
//cut windows in lower ring
clipped_by{
         #declare i=1;
         #while (i < 360)
         box{<-.07*dr,-.1,-or+.1*dr>,<.07*dr,hr+.1,-or+.23*dr>
         rotate y*i inverse}    
         box{<-.07*dr,-.1,-or+.3*dr>,<.07*dr,hr+.1,-or+.43*dr>
         rotate y*i inverse}
         #declare i=i+3;
         #end 
}}

object{ construct
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{-x,0} rotate y*20}
 clipped_by{plane{ x,0} rotate y*(-20)}}

object{ construct
  texture {pigment { color red 1 green 1 blue 1 } finish { phong 1 } }
 clipped_by{plane{ z,0} rotate y*(-20)}
 clipped_by{plane{-z,0} rotate y*  20}}

#include "spokes.inc"

//lower parts

cylinder {<-ls,0,0><ls,0,0> rs open scale <1.,.6,1.> translate hs*y}
cylinder {<0,0,-ls><0,0,ls> rs open scale <1.,.6,1>  translate hs*y }

cylinder {<-ir,hs/1.5,0><ir,hs/1.5,0> rss open translate<0,0,rs*2.5>}
cylinder {<-ir,hs/1.5,0><ir,hs/1.5,0> rss open translate<0,0,rs*1.7>}
cylinder {<-ir,hs/1.5,0><ir,hs/1.5,0> rss open translate<0,0,-rs*2.5>}
cylinder {<-ir,hs/1.5,0><ir,hs/1.5,0> rss open translate<0,0,-rs*1.7>}
cylinder {<0,hs/1.5,-ls><0,hs/1.5,ls> rss open translate<-rs*2.5,0,0>}
cylinder {<0,hs/1.5,-ls><0,hs/1.5,ls> rss open translate<-rs*1.7,0,0>}
cylinder {<0,hs/1.5,-ls><0,hs/1.5,ls> rss open translate<rs*2.5,0,0>}
cylinder {<0,hs/1.5,-ls><0,hs/1.5,ls> rss open translate<rs*1.7,0,0>}


//ring under construction
disc { <0, 0, 0>,<0,1,0>,or  or -dr*.1 }
disc { <0,tc, 0>,<0,1,0>,or  or -dr*.1 }
disc { <0, 0, 0>,<0,1,0>,or -dr*.9 or -dr }
disc { <0,tc, 0>,<0,1,0>,or -dr*.9 or -dr }
disc { <0,hr,	 0>,<0,1,0>,or	or -dr*.1 }
disc { <0,hr-tc, 0>,<0,1,0>,or	or -dr*.1 }
disc { <0,hr,	 0>,<0,1,0>,or -dr*.9 or -dr }
disc { <0,hr-tc, 0>,<0,1,0>,or -dr*.9 or -dr }

cylinder { <0,0,0>,	<0,hr*.1,0>,or	 open }
cylinder { <0,hr*0.9,0>,<0,hr,0>,   or	 open }
cylinder { <0,0,0>,	<0,hr*.1,0>,or -dr  open }
cylinder { <0,hr*0.9,0>,<0,hr,0>,   or -dr  open }

cylinder { <0,0,0>,	<0,hr*.1,0>,or-.1*dr   open }
cylinder { <0,hr*0.9,0>,<0,hr,0>,   or-.1*dr   open }
cylinder { <0,0,0>,	<0,hr*.1,0>,or-.9*dr  open }
cylinder { <0,hr*0.9,0>,<0,hr,0>,   or-.9*dr  open }


#declare i=0
#while (i < 361)
 box{<-.006,0.,-.8>,  <.006, .1,-.8+tc> rotate y*i}
#declare i=i+10;
#end 

//axis cylinder
cylinder {<0,0,0><0,hm,0> rm open}
cylinder {<0,ha-hm,0><0,ha,0> rm open}
cone {<0,hm,0> rm <0,hm+hc,0> ra open }
cone {<0,ha-hm-hc,0> ra <0,ha-hm,0> rm open}
cylinder {<0,hm+hc,0><0,ha-hm-hc,0> ra open}

//texture for all parts
texture {pigment { color red 1 green 1 blue 1 } finish { specular 0.5 } 
 } //end of objects
//bounding for the whole station
bounded_by
{cylinder{<0,-.01,0><0,ha+.01,0> or+.01}}
}} //end of station.inc