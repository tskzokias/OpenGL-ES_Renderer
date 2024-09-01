/********** AUTHOR NAME: TAKSH GOYAL ********************************
 ********** ORGANIZATION: AJNALENS (DIMENSIONNXG PVT. LTD.)**********
 ********** DATE: 18:03:2024 ****************************************
 ********** FILENAME: IShape.h ************************************/

#ifndef CUSTOMLAUNCHER_SHAPE_H
#define CUSTOMLAUNCHER_SHAPE_H

#endif //CUSTOMLAUNCHER_SHAPE_H

/* This is an interface class, this helps us in creating and executing
 * the shapes that we want to be rendered on screen
 * For now we will be creating two of them, i.e. Triangles and Rectangles
 * */
class IShape
{
public:
    virtual void Render() = 0;
    virtual void SetViewport(int width, int height) = 0;
    virtual bool Init() = 0;
};
