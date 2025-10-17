function distance(x1, y1, z1, x2, y2, z2) {
    d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2)
    return sqrt(d)
}


BEGIN {
    FS = ","
    Battery = 0 
    loc = -1
    crash = 0
    jump_len = 0
    path_len = 0
}

{
    if($1=="ATOM" && ($3=="N" || $3=="CA" || $3=="C")) {

        if(loc == -1) {
            loc = $6
            x = $7
            y = $8
            z = $9
        }
        else {
            dis = distance(x, y, z, $7, $8, $9)
            if($6 - loc > 1){
                if (Battery >= dis*5){
                    Battery -= dis*5
                    jump_len +=dis
                }
                else {
                    if(crash == 0){
                    print "The vehicle crashed at atomic point " $2 " after " path_len " Angstrom drive and " jump_len " Angstrom jump."
                    crash = 1
                    }
                }
            }
            else {
                Battery += dis*0.2
                if(Battery>100) {Battery = 100}
                path_len +=dis
            }
            loc = $6
            x = $7
            y = $8
            z = $9
        }
    
    }
}

END {
    if(crash == 0)
        print "The total distance traveled in Angstrom: drive distance= " path_len " and jump distance= "jump_len" , with remaining charge= "Battery"%" 
}

