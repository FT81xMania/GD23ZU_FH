
void icon3Zoom(int numeroicono, int X, int Y, float zoom){
    GD.cmd_scale(F16(zoom),F16(zoom));
    GD.cmd_setmatrix();
    GD.Vertex2ii(X, Y, numeroicono);
}  
