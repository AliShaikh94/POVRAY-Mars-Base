 #declare delta=.22;
         #while (delta < 1.00)
         
cylinder{<-rs*2.5,ha-hs/1.5,0><rs*2.5,ha-hs/1.5,0>rss/2 open translate<0,0,or*delta>}
cylinder{<-rs*2.5,ha-hs/1.5,0><rs*2.5,ha-hs/1.5,0>rss/2 open translate<0,0,-or*delta>}
cylinder{<-rs*2.5,hs/1.5,0><rs*2.5,hs/1.5,0>rss/2 open translate<0,0,or*delta>}
cylinder{<-rs*2.5,hs/1.5,0><rs*2.5,hs/1.5,0>rss/2 open translate<0,0,-or*delta>}
cylinder{<0,ha-hs/1.5,-rs*2.5><0,ha-hs/1.5,rs*2.5>rss/2 open translate<or*delta,0,0>}
cylinder{<0,ha-hs/1.5,-rs*2.5><0,ha-hs/1.5,rs*2.5>rss/2 open translate<-or*delta,0,0>}
cylinder{<0,hs/1.5,-rs*2.5><0,hs/1.5,rs*2.5>rss/2 open translate<or*delta,0,0>}
cylinder{<0,hs/1.5,-rs*2.5><0,hs/1.5,rs*2.5>rss/2 open translate<-or*delta,0,0>}
         #declare delta=delta+0.12;
         #end 
         