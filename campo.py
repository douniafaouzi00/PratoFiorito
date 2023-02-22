##import cppyy
##cppyy.include("lightsout.cpp")
##cppyy.include("fifteen.cpp")
##from cppyy.gbl import LightsOut, Fifteen

from boardgames import prato

import sys
sys.path.append('../../examples/')
from boardgame_g2d import BoardGameGui

##game = LightsOut(4, 5, 5)
w=int(input("w?"))
h=int(input("h?"))
n=int(input("n?"))
game = prato(w,h,n)
gui = BoardGameGui(game)
gui.main_loop()