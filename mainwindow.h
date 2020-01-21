#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL not vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkRenderingFreeType);

// FOR ARROW EXAMPLE
//=================================================================V
#include <vtkActor.h>
#include <vtkArrowSource.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkGenericOpenGLRenderWindow.h>

// FROM MAIN FILE
//=================================================================V
#include "vtkSmartPointer.h"
#include "vtkStructuredPointsReader.h"
#include "vtkMarchingCubes.h"
#include "vtkPolyDataConnectivityFilter.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include <vtkNamedColors.h>
#include <vtkLight.h>
#include <vtkStructuredPoints.h>
#include <vtkInteractorStyleTrackballCamera.h>

#include <vtkPolyDataMapper.h>
#include <vtkObjectFactory.h>
#include <vtkActor.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkCallbackCommand.h>
#include <vtkCommand.h>

// NEW OSPRAY CODE
//=================================================================V
#include "vtkOSPRayPass.h"
#include <vtkInformation.h>
#include <vtkOSPRayRendererNode.h>
#include <vtkPlane.h>
#include "vtkInformationStringKey.h"
#include <vtkOSPRayMaterialLibrary.h>
#include <vtkCompositePolyDataMapper2.h>
#include <vtkOSPRayLightNode.h>

// FOR VTK
//=================================================================V
#include <vtkSmartPointer.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGenericDataObjectReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkNamedColors.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>

// FOR LINE
//=================================================================V
#include <vtkSmartPointer.h>
#include <vtkLineSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkDoubleArray.h>
#include <vtkPolyLine.h>
#include <vtkNamedColors.h>
#include <vtkPointData.h>
// FOR TUBE
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkTubeFilter.h>
// FOR OUTLINE
#include <vtkOutlineFilter.h>
#include <vtkPlaneSource.h>
// FOR LIGHTING
#include <vtkLight.h>
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

// FOR TEXTURE
//=================================================================V
#include <iostream>
#include <vtkJPEGReader.h>
#include <vtkImageData.h>
#include <vtkImageViewer2.h>
#include <vtkImageActor.h>
#include <vtkSuperquadricSource.h>
#include <vtkCamera.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkJPEGWriter.h>
#include <vtkInteractorStyleImage.h>
#include <vtkImageCanvasSource2D.h>

// FOR VOLUME
//=================================================================V
#include <vtkStructuredPointsReader.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkVolume.h>
#include <vtkImageDataGeometryFilter.h>
#include <vtkXMLImageDataReader.h>
#include <vtkStructuredPoints.h>
#include <vtkNamedColors.h>
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include <vtkOutlineFilter.h>
#include "vtkPolyDataMapper.h"

// FOR SURFACE
//=================================================================V
#include "vtkSmartPointer.h"
#include "vtkStructuredPointsReader.h"
#include "vtkMarchingCubes.h"
#include "vtkPolyDataConnectivityFilter.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include <vtkNamedColors.h>
#include <vtkLight.h>
#include <vtkStructuredPoints.h>

// FOR WEEK5
//=================================================================V
#include <vtkGenericDataObjectReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>
#include "vtkProperty.h"
#include <vtkOutlineFilter.h>
#include <vtkOBJReader.h>
#include <vtkPlane.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkPlaneSource.h>
#include <vtkTransform.h>
#include <vtkSphereSource.h>
#include <vtkTransform.h>
#include <vtkTransformFilter.h>
#include <vtkPolyDataReader.h>
#include <vtkPLYReader.h>
#include <vtkTubeFilter.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void arrowClickMe();

    // FOR LINE
    vtkSmartPointer<vtkActor> returnLineTubeActor(double LINE_radius, int LINE_numSides, double LINE_opacity);

    // FOR VOLUME
    void volume_loadDataFromFile(const char* fileName);  // This function loads data from vtk file
    vtkSmartPointer<vtkProp> generateVolumeActor(double VOL_X1, double VOL_X2,  // This function generates a volume actor for rendering
        double VOL_X3, double VOL_X4, double VOL_X5, double VOL_X6, double VOL_X7,
        double VOL_X8, double VOL_X9, double VOL_Y1, double VOL_Y2, double VOL_Y3,
        double VOL_Y4, double VOL_Y5, double VOL_Y6, double VOL_Y7, double VOL_Y8,
        double VOL_Y9);
    vtkSmartPointer<vtkActor> generateOutlineActor();    // This function generates an outline actor for rendering

    //FOR SURFACE
    void surface_loadDataFromFile(const char* fileName);  // This function will load the vtkStructuredPoint data from a VTK file
    vtkSmartPointer<vtkActor>  generateIsoSurface(float threshold, double rr, double gg, double bb);    // This function will load myData and return an actor

    //FOR WEEK5
    vtkSmartPointer<vtkActor> readAndReturnCluster1Actor(const char* fileName, double rr, double gg, double bb);
    vtkSmartPointer<vtkActor> readAndReturnCluster2Actor(const char* fileName, double rr, double gg, double bb);
    vtkSmartPointer<vtkActor> readAndReturnPlaneActor(const char* fileName);
    vtkSmartPointer<vtkActor> generateOutlineActor(const char* fileName);

private:
    Ui::MainWindow *ui;
    // FROM MAIN
    //-----------------------------------------------------------V
     vtkSmartPointer<vtkGenericOpenGLRenderWindow> window;
     vtkSmartPointer<vtkRenderWindowInteractor> interactor;
     vtkSmartPointer<vtkRenderer> renderer;
     vtkSmartPointer<vtkActor> vtklineActor;
     vtkSmartPointer<vtkActor> lineActor;
     vtkSmartPointer<vtkProp> volumeActor;
     //vtkSmartPointer<vtkProp> volumeOutlineActor;
     //vtkSmartPointer<vtkActor> surfaceActor;
     //vtkSmartPointer<vtkActor> surfaceActor2;
     //vtkSmartPointer<vtkActor> cluster1Actor;
     //vtkSmartPointer<vtkActor> cluster2Actor;
     //vtkSmartPointer<vtkActor> planeActor;
     vtkSmartPointer<vtkActor> objActor;
     vtkSmartPointer<vtkActor> actor;

     // FOR LINE
     //-----------------------------------------------------------V
     vtkSmartPointer<vtkNamedColors> colors;
     vtkSmartPointer<vtkPoints> points;
     vtkSmartPointer<vtkPolyData> polyData;
     vtkSmartPointer<vtkCellArray> lines;
     vtkSmartPointer<vtkPolyLine> line;
     vtkSmartPointer<vtkDoubleArray> scalarValues;
     vtkSmartPointer<vtkUnsignedCharArray> colorsPolyTest;
     vtkSmartPointer<vtkTubeFilter> tubePolyLineFilter;
     vtkSmartPointer<vtkPolyDataMapper> tubeMapper;
     vtkSmartPointer<vtkActor> tubeActor;

     // FOR VOLUME
     //-----------------------------------------------------------V
     vtkSmartPointer<vtkImageData> volumeImageData;
     vtkSmartPointer<vtkStructuredPointsReader> reader;
     vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper;
     vtkSmartPointer<vtkVolumeProperty> volumeProperty;
     vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity;
     vtkSmartPointer<vtkColorTransferFunction> volumeColor;
     vtkSmartPointer<vtkVolume> volumeVolume;
     vtkSmartPointer<vtkOutlineFilter> volumeOutline;
     vtkSmartPointer<vtkPolyDataMapper> volumeOutlineMapper;
     vtkSmartPointer<vtkActor> volumeOutlineActor;
     //vtkSmartPointer<vtkProp> volumeOutlineActor;
     vtkInformation* rendererInfo;

     // FOR SURFACE
     //-----------------------------------------------------------V
     vtkSmartPointer<vtkStructuredPoints> myData;
     vtkSmartPointer<vtkMarchingCubes> mc;
     vtkSmartPointer<vtkPolyDataMapper> mapper;
     vtkSmartPointer<vtkPolyDataConnectivityFilter> confilter;
     vtkSmartPointer<vtkActor> surfaceActor;
     vtkSmartPointer<vtkActor> surfaceActor2;
     vtkSmartPointer<vtkStructuredPointsReader> surfaceReader;

     // FOR WEEK5
     //-----------------------------------------------------------V
     vtkSmartPointer<vtkGenericDataObjectReader> WEEK5_reader;
     vtkSmartPointer<vtkPolyDataMapper> WEEK5_mapper;
     vtkSmartPointer<vtkActor> cluster1Actor;
     vtkSmartPointer<vtkActor> cluster2Actor;
     vtkSmartPointer<vtkActor> planeActor;
     vtkPolyData* cluster1Output;
     vtkPolyData* cluster2Output;

     // FOR MISC
     //-----------------------------------------------------------V
     bool vtkBool = NULL;
     bool lineBool = NULL;
     bool textureBool = NULL;
     bool volumeBool = NULL;
     bool surfaceBool = NULL;
     bool week5Bool = NULL;
     std::string ALL_rendererString;

     int VOL_sppValue;
     int VOL_ambientSamplesValue;
     int VOL_compositeValue;

     int SUR_sppValue;
     int SUR_ambientSamplesValue;
     int SUR_compositeValue;
     char* SUR_fileName;

     int W5_sppValue;
     int W5_ambientSamplesValue;
     int W5_compositeValue;

     double VOL_X1;
     double VOL_Y1;
     double VOL_X2;
     double VOL_Y2;
     double VOL_X3;
     double VOL_Y3;
     double VOL_X4;
     double VOL_Y4;
     double VOL_X5;
     double VOL_Y5;
     double VOL_X6;
     double VOL_Y6;
     double VOL_X7;
     double VOL_Y7;
     double VOL_X8;
     double VOL_Y8;
     double VOL_X9;
     double VOL_Y9;

     // FOR LIGHTS
     //-----------------------------------------------------------V
     /*
     //auto shadowColors = vtkSmartPointer<vtkNamedColors>::New();
     auto light1 = vtkSmartPointer<vtkLight>::New();
     auto light2 = vtkSmartPointer<vtkLight>::New();
     auto light3 = vtkSmartPointer<vtkLight>::New();
     auto light4 = vtkSmartPointer<vtkLight>::New();
     auto light5 = vtkSmartPointer<vtkLight>::New();
     auto light6 = vtkSmartPointer<vtkLight>::New();
     auto light7 = vtkSmartPointer<vtkLight>::New();
     auto light8 = vtkSmartPointer<vtkLight>::New();
     auto light9 = vtkSmartPointer<vtkLight>::New();
     auto light10 = vtkSmartPointer<vtkLight>::New();
     */

     vtkSmartPointer<vtkLight> light1;
     vtkSmartPointer<vtkLight> light2;
     vtkSmartPointer<vtkLight> light3;
     vtkSmartPointer<vtkLight> light4;
     vtkSmartPointer<vtkLight> light5;
     vtkSmartPointer<vtkLight> light6;
     vtkSmartPointer<vtkLight> light7;
     vtkSmartPointer<vtkLight> light8;
     vtkSmartPointer<vtkLight> light9;
     vtkSmartPointer<vtkLight> light10;

     /*
     bool light1Bool = NULL;
     bool light2Bool = NULL;
     bool light3Bool = NULL;
     bool light4Bool = NULL;
     bool light5Bool = NULL;
     bool light6Bool = NULL;
     bool light7Bool = NULL;
     bool light8Bool = NULL;
     bool light9Bool = NULL;
     bool light10Bool = NULL;
     */

     int num1light;
     double LIGHT1POS1;
     double LIGHT1POS2;
     double LIGHT1POS3;
     double LIGHT1COLOR1;
     double LIGHT1COLOR2;
     double LIGHT1COLOR3;
     double LIGHT1INTENSITY;

     int num2light;
     double LIGHT2POS1;
     double LIGHT2POS2;
     double LIGHT2POS3;
     double LIGHT2COLOR1;
     double LIGHT2COLOR2;
     double LIGHT2COLOR3;
     double LIGHT2INTENSITY;

     int num3light;
     double LIGHT3POS1;
     double LIGHT3POS2;
     double LIGHT3POS3;
     double LIGHT3COLOR1;
     double LIGHT3COLOR2;
     double LIGHT3COLOR3;
     double LIGHT3INTENSITY;

     int num4light;
     double LIGHT4POS1;
     double LIGHT4POS2;
     double LIGHT4POS3;
     double LIGHT4COLOR1;
     double LIGHT4COLOR2;
     double LIGHT4COLOR3;
     double LIGHT4INTENSITY;

     int num5light;
     double LIGHT5POS1;
     double LIGHT5POS2;
     double LIGHT5POS3;
     double LIGHT5COLOR1;
     double LIGHT5COLOR2;
     double LIGHT5COLOR3;
     double LIGHT5INTENSITY;

     int num6light;
     double LIGHT6POS1;
     double LIGHT6POS2;
     double LIGHT6POS3;
     double LIGHT6COLOR1;
     double LIGHT6COLOR2;
     double LIGHT6COLOR3;
     double LIGHT6INTENSITY;

     int num7light;
     double LIGHT7POS1;
     double LIGHT7POS2;
     double LIGHT7POS3;
     double LIGHT7COLOR1;
     double LIGHT7COLOR2;
     double LIGHT7COLOR3;
     double LIGHT7INTENSITY;

     int num8light;
     double LIGHT8POS1;
     double LIGHT8POS2;
     double LIGHT8POS3;
     double LIGHT8COLOR1;
     double LIGHT8COLOR2;
     double LIGHT8COLOR3;
     double LIGHT8INTENSITY;

     int num9light;
     double LIGHT9POS1;
     double LIGHT9POS2;
     double LIGHT9POS3;
     double LIGHT9COLOR1;
     double LIGHT9COLOR2;
     double LIGHT9COLOR3;
     double LIGHT9INTENSITY;

     int num10light;
     double LIGHT10POS1;
     double LIGHT10POS2;
     double LIGHT10POS3;
     double LIGHT10COLOR1;
     double LIGHT10COLOR2;
     double LIGHT10COLOR3;
     double LIGHT10INTENSITY;

     double LINE_radius;
     int LINE_numSides;
     double LINE_opacity;


};

#endif // MAINWINDOW_H
