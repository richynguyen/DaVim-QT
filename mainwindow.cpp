#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

// MAIN
//-------------------------------------------------------------------V
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Part of original code
    ui->setupUi(this);

    // Visualize
    interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
    window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    window->AddRenderer(renderer);
    qDebug()<<"something here in Clickme \n";

    // this is for rendering the image
    ui->openGLWidget->SetRenderWindow(window);

    // ---------TESTINGGGG SET RENDERING ENGINE---------
    //-------------------------------------------------------------------V
    //renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkInformation* rendererInfo = renderer->GetInformation();
    //rendererInfo = renderer->GetInformation();
    qDebug() << "Rendering engine: " << ui->comboBox->currentText();
    QString ALL_rendererString = ui->comboBox->currentText();
    rendererInfo->Set(vtkOSPRayRendererNode::RENDERER_TYPE(), "scivis");
    //rendererInfo->Set(vtkOSPRayRendererNode::RENDERER_TYPE(), ALL_rendererString);
    //rendererInfo->Set(vtkOSPRayRendererNode::RENDERER_TYPE(), ui->comboBox->currentText());

    connect(ui->pushButton,SIGNAL(released()),this,SLOT(arrowClickMe()));
}


// FOR ARROW CLICK ME RENDER BUTTON
//-------------------------------------------------------------------V
void MainWindow::arrowClickMe()
{
    ui->label->setText("Rendered");


    // FOR LINE
    //-------------------------------------------------------------------V
    qDebug() << "TESTING LINE";
    qDebug() << ui->comboBox_3->currentText();  // on/off

    QString LINE_radius_text = ui->lineEdit->text();
    double LINE_radius = LINE_radius_text.toDouble();

    QString LINE_numSides_text = ui->lineEdit_2->text();
    int LINE_numSides = LINE_numSides_text.toDouble();

    QString LINE_opacity_text = ui->lineEdit_3->text();
    double LINE_opacity = LINE_opacity_text.toDouble();

    qDebug() << "Line on/off: " << ui->comboBox_3->currentText();
    qDebug() << "Line radius: " << LINE_radius;
    qDebug() << "Line num sides: " << LINE_numSides;
    qDebug() << "Line opacity: " << LINE_opacity;

    lineActor = returnLineTubeActor(LINE_radius, LINE_numSides, LINE_opacity);


    // FOR VOLUME
    //-------------------------------------------------------------------V
    qDebug() << "TESTING VOLUME";
    qDebug() << ui->comboBox_5->currentText();  // on/off

    /**/
    // FOR SAMPLES PER PIXEL
    QString VOL_sppValue_text = ui->lineEdit_11->text();
    int VOL_sppValue = VOL_sppValue_text.toInt();

    // FOR AMBIENT SAMPLES
    QString VOL_ambientSamplesValue_text = ui->comboBox_9->currentText();
    int VOL_ambientSamplesValue = VOL_ambientSamplesValue_text.toInt();

    // FOR COMPOSITE VALUE
    QString VOL_compositeValue_text = ui->comboBox_6->currentText();
    int VOL_compositeValue = VOL_compositeValue_text.toInt();

    /**/
    // FOR OPACITY
    QString VOL_X1_text = ui->lineEdit_4->text();
    double VOL_X1 = VOL_X1_text.toDouble();

    QString VOL_Y1_text = ui->lineEdit_5->text();
    double VOL_Y1 = VOL_X1_text.toDouble();

    QString VOL_X2_text = ui->lineEdit_6->text();
    double VOL_X2 = VOL_X2_text.toDouble();

    QString VOL_Y2_text = ui->lineEdit_7->text();
    double VOL_Y2 = VOL_Y2_text.toDouble();

    QString VOL_X3_text = ui->lineEdit_8->text();
    double VOL_X3 = VOL_X3_text.toDouble();

    QString VOL_Y3_text = ui->lineEdit_9->text();
    double VOL_Y3 = VOL_Y3_text.toDouble();

    QString VOL_X4_text = ui->lineEdit_10->text();
    double VOL_X4 = VOL_X4_text.toDouble();

    QString VOL_Y4_text = ui->lineEdit_12->text();
    double VOL_Y4 = VOL_Y4_text.toDouble();

    QString VOL_X5_text = ui->lineEdit_13->text();
    double VOL_X5 = VOL_X5_text.toDouble();

    QString VOL_Y5_text = ui->lineEdit_14->text();
    double VOL_Y5 = VOL_Y5_text.toDouble();

    QString VOL_X6_text = ui->lineEdit_15->text();
    double VOL_X6 = VOL_X6_text.toDouble();

    QString VOL_Y6_text = ui->lineEdit_16->text();
    double VOL_Y6 = VOL_Y6_text.toDouble();

    QString VOL_X7_text = ui->lineEdit_17->text();
    double VOL_X7 = VOL_X7_text.toDouble();

    QString VOL_Y7_text = ui->lineEdit_18->text();
    double VOL_Y7 = VOL_Y7_text.toDouble();

    QString VOL_X8_text = ui->lineEdit_19->text();
    double VOL_X8 = VOL_X8_text.toDouble();

    QString VOL_Y8_text = ui->lineEdit_20->text();
    double VOL_Y8 = VOL_Y8_text.toDouble();

    QString VOL_X9_text = ui->lineEdit_21->text();
    double VOL_X9 = VOL_X9_text.toDouble();

    QString VOL_Y9_text = ui->lineEdit_22->text();
    double VOL_Y9 = VOL_Y9_text.toDouble();

    // TEST PRINT VOLUME VALUES
    qDebug() << "VOL_sppValue: " << VOL_sppValue;
    qDebug() << "VOL_ambientSamplesValue: " << VOL_ambientSamplesValue;
    qDebug() << "VOL_compositeValue: " << VOL_compositeValue;
    qDebug() << "X1: " << VOL_X1;
    qDebug() << "Y1: " << VOL_Y1;
    qDebug() << "X2: " << VOL_X2;
    qDebug() << "Y2: " << VOL_Y2;
    qDebug() << "X3: " << VOL_X3;
    qDebug() << "Y3: " << VOL_Y3;
    qDebug() << "X4: " << VOL_X4;
    qDebug() << "Y4: " << VOL_Y4;
    qDebug() << "X5: " << VOL_X5;
    qDebug() << "Y5: " << VOL_Y5;
    qDebug() << "X6: " << VOL_X6;
    qDebug() << "Y6: " << VOL_Y6;
    qDebug() << "X7: " << VOL_X7;
    qDebug() << "Y7: " << VOL_Y7;
    qDebug() << "X8: " << VOL_X8;
    qDebug() << "Y8: " << VOL_Y8;
    qDebug() << "X9: " << VOL_X9;
    qDebug() << "Y9: " << VOL_Y9;

    volume_loadDataFromFile("tac_volume_cylinder_curl_onefourth.vtk");
    volumeActor = generateVolumeActor(VOL_X1, VOL_X2, VOL_X3, VOL_X4,
                    VOL_X5, VOL_X6, VOL_X7, VOL_X8, VOL_X9, VOL_Y1, VOL_Y2, VOL_Y3, VOL_Y4,
                    VOL_Y5, VOL_Y6, VOL_Y7, VOL_Y8, VOL_Y9);
    volumeOutlineActor = generateOutlineActor();


    // FOR SURFACE
    //-------------------------------------------------------------------V
    qDebug() << "Testing Surface";
    qDebug() << ui->comboBox_7->currentText();  // on/off

    // FOR SAMPLES PER PIXEL
    QString SUR_sppValue_text = ui->lineEdit_24->text();
    int SUR_sppValue = SUR_sppValue_text.toInt();

    // FOR AMBIENT SAMPLES
    QString SUR_ambientSamplesValue_text = ui->comboBox_8->currentText();
    int SUR_ambientSamplesValue = SUR_ambientSamplesValue_text.toInt();

    // FOR COMPOSITE VALUE
    QString SUR_compositeValue_text = ui->comboBox_10->currentText();
    int SUR_compositeValue = SUR_compositeValue_text.toInt();

    // TEST PRINT
    qDebug() << "SUR_sppValue: " << SUR_sppValue;
    qDebug() << "SUR_ambientSamplesValue: " << SUR_ambientSamplesValue;
    qDebug() << "SUR_compositeValue: " << SUR_compositeValue;

    surface_loadDataFromFile("tac_volume_cylinder_curl_onefourth.vtk");
    float threshold = 0.5;
    float threshold2 = 7;
    surfaceActor = generateIsoSurface(threshold, 1.0, 0.0, 0.0);
    surfaceActor2 = generateIsoSurface(threshold2, 0.0, 0.0, 1.0);


    // FOR WEEK5
    //-------------------------------------------------------------------V
    qDebug() << "Testing Week5";
    qDebug() << ui->comboBox_11->currentText();  // on/off

    // FOR SAMPLES PER PIXEL
    QString W5_sppValue_text = ui->lineEdit_25->text();
    int W5_sppValue = W5_sppValue_text.toInt();

    // FOR AMBIENT SAMPLES
    QString W5_ambientSamplesValue_text = ui->comboBox_12->currentText();
    int W5_ambientSamplesValue = W5_ambientSamplesValue_text.toInt();

    // FOR COMPOSITE VALUE
    QString W5_compositeValue_text = ui->comboBox_13->currentText();
    int W5_compositeValue = W5_compositeValue_text.toInt();

    // TEST PRINT
    qDebug() << "W5_sppValue: " << W5_sppValue;
    qDebug() << "W5_ambientSamplesValue: " << W5_ambientSamplesValue;
    qDebug() << "W5_compositeValue: " << W5_compositeValue;

    cluster1Actor = readAndReturnCluster1Actor("cluster1.vtk", 252, 226, 5);
    cluster2Actor = readAndReturnCluster2Actor("cluster2.vtk", 0, 255, 255);
    planeActor = readAndReturnPlaneActor("plane.vtk");
    objActor = generateOutlineActor("tube_outerbox.obj");


    // FOR LIGHTS
    //-------------------------------------------------------------------V
    // LIGHT 1
    // ====================================================V
    qDebug() << "TEST LIGHT1";
    qDebug() << ui->comboBox_14->currentText();

    QString LIGHT1POS1_TEXT = ui->lineEdit_23->text();
    double LIGHT1POS1 = LIGHT1POS1_TEXT.toDouble();
    qDebug() << "LIGHT1POS1: " << LIGHT1POS1;

    QString LIGHT1POS2_TEXT = ui->lineEdit_26->text();
    double LIGHT1POS2 = LIGHT1POS2_TEXT.toDouble();
    qDebug() << "LIGHT1POS2: " << LIGHT1POS2;

    QString LIGHT1POS3_TEXT = ui->lineEdit_27->text();
    double LIGHT1POS3 = LIGHT1POS3_TEXT.toDouble();
    qDebug() << "LIGHT1POS3: " << LIGHT1POS3;

    QString LIGHT1COLOR1_TEXT = ui->lineEdit_28->text();
    double LIGHT1COLOR1 = LIGHT1COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT1COLOR1: " << LIGHT1COLOR1;

    QString LIGHT1COLOR2_TEXT = ui->lineEdit_29->text();
    double LIGHT1COLOR2 = LIGHT1COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT1COLOR2: " << LIGHT1COLOR2;

    QString LIGHT1COLOR3_TEXT = ui->lineEdit_30->text();
    double LIGHT1COLOR3 = LIGHT1COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT1COLOR3: " << LIGHT1COLOR3;

    QString LIGHT1INTENSITY_TEXT = ui->lineEdit_31->text();
    double LIGHT1INTENSITY = LIGHT1INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT1INTENSITY: " << LIGHT1INTENSITY;

    light1 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_14->currentText() == "on")
    {
        light1->SetFocalPoint(0, 0, 0);
        light1->SetPosition(LIGHT1POS1, LIGHT1POS2, LIGHT1POS3);
        light1->SetColor(LIGHT1COLOR1, LIGHT1COLOR2, LIGHT1COLOR3);
        light1->SetIntensity(LIGHT1INTENSITY);
    }


    // LIGHT 2
    // ====================================================V
    qDebug() << "TEST LIGHT 2";
    qDebug() << ui->comboBox_15->currentText();

    QString LIGHT2POS1_TEXT = ui->lineEdit_32->text();
    double LIGHT2POS1 = LIGHT2POS1_TEXT.toDouble();
    qDebug() << "LIGHT2POS1: " << LIGHT2POS1;

    QString LIGHT2POS2_TEXT = ui->lineEdit_33->text();
    double LIGHT2POS2 = LIGHT2POS2_TEXT.toDouble();
    qDebug() << "LIGHT2POS2: " << LIGHT2POS2;

    QString LIGHT2POS3_TEXT = ui->lineEdit_34->text();
    double LIGHT2POS3 = LIGHT2POS3_TEXT.toDouble();
    qDebug() << "LIGHT2POS3: " << LIGHT2POS3;

    QString LIGHT2COLOR1_TEXT = ui->lineEdit_36->text();
    double LIGHT2COLOR1 = LIGHT2COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT2COLOR1: " << LIGHT2COLOR1;

    QString LIGHT2COLOR2_TEXT = ui->lineEdit_35->text();
    double LIGHT2COLOR2 = LIGHT2COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT2COLOR2: " << LIGHT2COLOR2;

    QString LIGHT2COLOR3_TEXT = ui->lineEdit_36->text();
    double LIGHT2COLOR3 = LIGHT2COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT2COLOR3: " << LIGHT2COLOR3;

    QString LIGHT2INTENSITY_TEXT = ui->lineEdit_38->text();
    double LIGHT2INTENSITY = LIGHT2INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT2INTENSITY: " << LIGHT2INTENSITY;

    light2 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_15->currentText() == "on")
    {
        light2->SetFocalPoint(0, 0, 0);
        light2->SetPosition(LIGHT2POS1, LIGHT2POS2, LIGHT2POS3);
        light2->SetColor(LIGHT2COLOR1, LIGHT2COLOR2, LIGHT2COLOR3);
        light2->SetIntensity(LIGHT2INTENSITY);
    }


    // LIGHT 3
    // ====================================================V
    qDebug() << "TEST LIGHT 3";
    qDebug() << ui->comboBox_16->currentText();

    QString LIGHT3POS1_TEXT = ui->lineEdit_39->text();
    double LIGHT3POS1 = LIGHT3POS1_TEXT.toDouble();
    qDebug() << "LIGHT3POS1: " << LIGHT3POS1;

    QString LIGHT3POS2_TEXT = ui->lineEdit_40->text();
    double LIGHT3POS2 = LIGHT3POS2_TEXT.toDouble();
    qDebug() << "LIGHT3POS2: " << LIGHT3POS2;

    QString LIGHT3POS3_TEXT = ui->lineEdit_41->text();
    double LIGHT3POS3 = LIGHT3POS3_TEXT.toDouble();
    qDebug() << "LIGHT3POS3: " << LIGHT3POS3;

    QString LIGHT3COLOR1_TEXT = ui->lineEdit_42->text();
    double LIGHT3COLOR1 = LIGHT3COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT3COLOR1: " << LIGHT3COLOR1;

    QString LIGHT3COLOR2_TEXT = ui->lineEdit_44->text();
    double LIGHT3COLOR2 = LIGHT3COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT3COLOR2: " << LIGHT3COLOR2;

    QString LIGHT3COLOR3_TEXT = ui->lineEdit_43->text();
    double LIGHT3COLOR3 = LIGHT3COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT3COLOR3: " << LIGHT3COLOR3;

    QString LIGHT3INTENSITY_TEXT = ui->lineEdit_65->text();
    double LIGHT3INTENSITY = LIGHT3INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT3INTENSITY: " << LIGHT3INTENSITY;

    light3 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_16->currentText() == "on")
    {
        light3->SetFocalPoint(0, 0, 0);
        light3->SetPosition(LIGHT3POS1, LIGHT3POS2, LIGHT3POS3);
        light3->SetColor(LIGHT3COLOR1, LIGHT3COLOR2, LIGHT3COLOR3);
        light3->SetIntensity(LIGHT3INTENSITY);
    }


    // LIGHT 4
    // ====================================================V
    qDebug() << "TEST LIGHT 4";
    qDebug() << ui->comboBox_23->currentText();

    QString LIGHT4POS1_TEXT = ui->lineEdit_89->text();
    double LIGHT4POS1 = LIGHT4POS1_TEXT.toDouble();
    qDebug() << "LIGHT4POS1: " << LIGHT4POS1;

    QString LIGHT4POS2_TEXT = ui->lineEdit_87->text();
    double LIGHT4POS2 = LIGHT4POS2_TEXT.toDouble();
    qDebug() << "LIGHT4POS2: " << LIGHT4POS2;

    QString LIGHT4POS3_TEXT = ui->lineEdit_88->text();
    double LIGHT4POS3 = LIGHT4POS3_TEXT.toDouble();
    qDebug() << "LIGHT4POS3: " << LIGHT4POS3;

    QString LIGHT4COLOR1_TEXT = ui->lineEdit_92->text();
    double LIGHT4COLOR1 = LIGHT4COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT4COLOR1: " << LIGHT4COLOR1;

    QString LIGHT4COLOR2_TEXT = ui->lineEdit_90->text();
    double LIGHT4COLOR2 = LIGHT4COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT4COLOR2: " << LIGHT4COLOR2;

    QString LIGHT4COLOR3_TEXT = ui->lineEdit_91->text();
    double LIGHT4COLOR3 = LIGHT4COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT4COLOR3: " << LIGHT4COLOR3;

    QString LIGHT4INTENSITY_TEXT = ui->lineEdit_93->text();
    double LIGHT4INTENSITY = LIGHT4INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT4INTENSITY: " << LIGHT4INTENSITY;

    light4 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_23->currentText() == "on")
    {
        light4->SetFocalPoint(0, 0, 0);
        light4->SetPosition(LIGHT4POS1, LIGHT4POS2, LIGHT4POS3);
        light4->SetColor(LIGHT4COLOR1, LIGHT4COLOR2, LIGHT4COLOR3);
        light4->SetIntensity(LIGHT4INTENSITY);
    }


    // LIGHT 5
    // ====================================================V
    qDebug() << "TEST LIGHT 5";
    qDebug() << ui->comboBox_24->currentText();

    QString LIGHT5POS1_TEXT = ui->lineEdit_94->text();
    double LIGHT5POS1 = LIGHT5POS1_TEXT.toDouble();
    qDebug() << "LIGHT5POS1: " << LIGHT5POS1;

    QString LIGHT5POS2_TEXT = ui->lineEdit_96->text();
    double LIGHT5POS2 = LIGHT5POS2_TEXT.toDouble();
    qDebug() << "LIGHT5POS2: " << LIGHT5POS2;

    QString LIGHT5POS3_TEXT = ui->lineEdit_95->text();
    double LIGHT5POS3 = LIGHT5POS3_TEXT.toDouble();
    qDebug() << "LIGHT5POS3: " << LIGHT5POS3;

    QString LIGHT5COLOR1_TEXT = ui->lineEdit_97->text();
    double LIGHT5COLOR1 = LIGHT5COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT5COLOR1: " << LIGHT5COLOR1;

    QString LIGHT5COLOR2_TEXT = ui->lineEdit_98->text();
    double LIGHT5COLOR2 = LIGHT5COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT5COLOR2: " << LIGHT5COLOR2;

    QString LIGHT5COLOR3_TEXT = ui->lineEdit_99->text();
    double LIGHT5COLOR3 = LIGHT5COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT5COLOR3: " << LIGHT5COLOR3;

    QString LIGHT5INTENSITY_TEXT = ui->lineEdit_100->text();
    double LIGHT5INTENSITY = LIGHT5INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT5INTENSITY: " << LIGHT5INTENSITY;

    light5 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_24->currentText() == "on")
    {
        light5->SetFocalPoint(0, 0, 0);
        light5->SetPosition(LIGHT5POS1, LIGHT5POS2, LIGHT5POS3);
        light5->SetColor(LIGHT5COLOR1, LIGHT5COLOR2, LIGHT5COLOR3);
        light5->SetIntensity(LIGHT5INTENSITY);
    }


    // LIGHT 6
    // ====================================================V
    qDebug() << "TEST LIGHT 6";
    qDebug() << ui->comboBox_25->currentText();

    QString LIGHT6POS1_TEXT = ui->lineEdit_101->text();
    double LIGHT6POS1 = LIGHT6POS1_TEXT.toDouble();
    qDebug() << "LIGHT6POS1: " << LIGHT6POS1;

    QString LIGHT6POS2_TEXT = ui->lineEdit_102->text();
    double LIGHT6POS2 = LIGHT6POS2_TEXT.toDouble();
    qDebug() << "LIGHT6POS2: " << LIGHT6POS2;

    QString LIGHT6POS3_TEXT = ui->lineEdit_103->text();
    double LIGHT6POS3 = LIGHT6POS3_TEXT.toDouble();
    qDebug() << "LIGHT6POS3: " << LIGHT6POS3;

    QString LIGHT6COLOR1_TEXT = ui->lineEdit_104->text();
    double LIGHT6COLOR1 = LIGHT6COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT6COLOR1: " << LIGHT6COLOR1;

    QString LIGHT6COLOR2_TEXT = ui->lineEdit_105->text();
    double LIGHT6COLOR2 = LIGHT6COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT6COLOR2: " << LIGHT6COLOR2;

    QString LIGHT6COLOR3_TEXT = ui->lineEdit_106->text();
    double LIGHT6COLOR3 = LIGHT6COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT6COLOR3: " << LIGHT6COLOR3;

    QString LIGHT6INTENSITY_TEXT = ui->lineEdit_107->text();
    double LIGHT6INTENSITY = LIGHT6INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT6INTENSITY: " << LIGHT6INTENSITY;

    light6 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_25->currentText() == "on")
    {
        light6->SetFocalPoint(0, 0, 0);
        light6->SetPosition(LIGHT6POS1, LIGHT6POS2, LIGHT6POS3);
        light6->SetColor(LIGHT6COLOR1, LIGHT6COLOR2, LIGHT6COLOR3);
        light6->SetIntensity(LIGHT6INTENSITY);
    }


    // LIGHT 7
    // ====================================================V
    qDebug() << "TEST LIGHT 7";
    qDebug() << ui->comboBox_26->currentText();

    QString LIGHT7POS1_TEXT = ui->lineEdit_108->text();
    double LIGHT7POS1 = LIGHT7POS1_TEXT.toDouble();
    qDebug() << "LIGHT7POS1: " << LIGHT7POS1;

    QString LIGHT7POS2_TEXT = ui->lineEdit_109->text();
    double LIGHT7POS2 = LIGHT7POS2_TEXT.toDouble();
    qDebug() << "LIGHT7POS2: " << LIGHT7POS2;

    QString LIGHT7POS3_TEXT = ui->lineEdit_110->text();
    double LIGHT7POS3 = LIGHT7POS3_TEXT.toDouble();
    qDebug() << "LIGHT7POS3: " << LIGHT7POS3;

    QString LIGHT7COLOR1_TEXT = ui->lineEdit_111->text();
    double LIGHT7COLOR1 = LIGHT7COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT7COLOR1: " << LIGHT7COLOR1;

    QString LIGHT7COLOR2_TEXT = ui->lineEdit_112->text();
    double LIGHT7COLOR2 = LIGHT7COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT7COLOR2: " << LIGHT7COLOR2;

    QString LIGHT7COLOR3_TEXT = ui->lineEdit_113->text();
    double LIGHT7COLOR3 = LIGHT7COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT7COLOR3: " << LIGHT7COLOR3;

    QString LIGHT7INTENSITY_TEXT = ui->lineEdit_114->text();
    double LIGHT7INTENSITY = LIGHT7INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT7INTENSITY: " << LIGHT7INTENSITY;

    light7 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_26->currentText() == "on")
    {
        light7->SetFocalPoint(0, 0, 0);
        light7->SetPosition(LIGHT7POS1, LIGHT7POS2, LIGHT7POS3);
        light7->SetColor(LIGHT7COLOR1, LIGHT7COLOR2, LIGHT7COLOR3);
        light7->SetIntensity(LIGHT7INTENSITY);
    }


    // LIGHT 8
    // ====================================================V
    qDebug() << "TEST LIGHT 8";
    qDebug() << ui->comboBox_27->currentText();

    QString LIGHT8POS1_TEXT = ui->lineEdit_115->text();
    double LIGHT8POS1 = LIGHT8POS1_TEXT.toDouble();
    qDebug() << "LIGHT8POS1: " << LIGHT8POS1;

    QString LIGHT8POS2_TEXT = ui->lineEdit_116->text();
    double LIGHT8POS2 = LIGHT8POS2_TEXT.toDouble();
    qDebug() << "LIGHT8POS2: " << LIGHT8POS2;

    QString LIGHT8POS3_TEXT = ui->lineEdit_117->text();
    double LIGHT8POS3 = LIGHT8POS3_TEXT.toDouble();
    qDebug() << "LIGHT8POS3: " << LIGHT8POS3;

    QString LIGHT8COLOR1_TEXT = ui->lineEdit_118->text();
    double LIGHT8COLOR1 = LIGHT8COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT8COLOR1: " << LIGHT8COLOR1;

    QString LIGHT8COLOR2_TEXT = ui->lineEdit_119->text();
    double LIGHT8COLOR2 = LIGHT8COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT8COLOR2: " << LIGHT8COLOR2;

    QString LIGHT8COLOR3_TEXT = ui->lineEdit_120->text();
    double LIGHT8COLOR3 = LIGHT8COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT8COLOR3: " << LIGHT8COLOR3;

    QString LIGHT8INTENSITY_TEXT = ui->lineEdit_121->text();
    double LIGHT8INTENSITY = LIGHT8INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT8INTENSITY: " << LIGHT8INTENSITY;

    light8 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_27->currentText() == "on")
    {
        light8->SetFocalPoint(0, 0, 0);
        light8->SetPosition(LIGHT8POS1, LIGHT8POS2, LIGHT8POS3);
        light8->SetColor(LIGHT8COLOR1, LIGHT8COLOR2, LIGHT8COLOR3);
        light8->SetIntensity(LIGHT8INTENSITY);
    }


    // LIGHT 9
    // ====================================================V
    qDebug() << "TEST LIGHT 9";
    qDebug() << ui->comboBox_28->currentText();

    QString LIGHT9POS1_TEXT = ui->lineEdit_122->text();
    double LIGHT9POS1 = LIGHT9POS1_TEXT.toDouble();
    qDebug() << "LIGHT9POS1: " << LIGHT9POS1;

    QString LIGHT9POS2_TEXT = ui->lineEdit_123->text();
    double LIGHT9POS2 = LIGHT9POS2_TEXT.toDouble();
    qDebug() << "LIGHT9POS2: " << LIGHT9POS2;

    QString LIGHT9POS3_TEXT = ui->lineEdit_124->text();
    double LIGHT9POS3 = LIGHT9POS3_TEXT.toDouble();
    qDebug() << "LIGHT9POS3: " << LIGHT9POS3;

    QString LIGHT9COLOR1_TEXT = ui->lineEdit_125->text();
    double LIGHT9COLOR1 = LIGHT9COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT9COLOR1: " << LIGHT9COLOR1;

    QString LIGHT9COLOR2_TEXT = ui->lineEdit_126->text();
    double LIGHT9COLOR2 = LIGHT9COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT9COLOR2: " << LIGHT9COLOR2;

    QString LIGHT9COLOR3_TEXT = ui->lineEdit_127->text();
    double LIGHT9COLOR3 = LIGHT9COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT9COLOR3: " << LIGHT9COLOR3;

    QString LIGHT9INTENSITY_TEXT = ui->lineEdit_128->text();
    double LIGHT9INTENSITY = LIGHT9INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT9INTENSITY: " << LIGHT9INTENSITY;

    light9 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_28->currentText() == "on")
    {
        light9->SetFocalPoint(0, 0, 0);
        light9->SetPosition(LIGHT9POS1, LIGHT9POS2, LIGHT9POS3);
        light9->SetColor(LIGHT9COLOR1, LIGHT9COLOR2, LIGHT9COLOR3);
        light9->SetIntensity(LIGHT9INTENSITY);
    }


    // LIGHT 10
    // ====================================================V
    qDebug() << "TEST LIGHT 10";
    qDebug() << ui->comboBox_29->currentText();

    QString LIGHT10POS1_TEXT = ui->lineEdit_129->text();
    double LIGHT10POS1 = LIGHT10POS1_TEXT.toDouble();
    qDebug() << "LIGHT10POS1: " << LIGHT10POS1;

    QString LIGHT10POS2_TEXT = ui->lineEdit_130->text();
    double LIGHT10POS2 = LIGHT10POS2_TEXT.toDouble();
    qDebug() << "LIGHT10POS2: " << LIGHT10POS2;

    QString LIGHT10POS3_TEXT = ui->lineEdit_131->text();
    double LIGHT10POS3 = LIGHT10POS3_TEXT.toDouble();
    qDebug() << "LIGHT10POS3: " << LIGHT10POS3;

    QString LIGHT10COLOR1_TEXT = ui->lineEdit_132->text();
    double LIGHT10COLOR1 = LIGHT10COLOR1_TEXT.toDouble();
    qDebug() << "LIGHT10COLOR1: " << LIGHT10COLOR1;

    QString LIGHT10COLOR2_TEXT = ui->lineEdit_133->text();
    double LIGHT10COLOR2 = LIGHT10COLOR2_TEXT.toDouble();
    qDebug() << "LIGHT10COLOR2: " << LIGHT10COLOR2;

    QString LIGHT10COLOR3_TEXT = ui->lineEdit_134->text();
    double LIGHT10COLOR3 = LIGHT10COLOR3_TEXT.toDouble();
    qDebug() << "LIGHT10COLOR3: " << LIGHT10COLOR3;

    QString LIGHT10INTENSITY_TEXT = ui->lineEdit_135->text();
    double LIGHT10INTENSITY = LIGHT10INTENSITY_TEXT.toDouble();
    qDebug() << "LIGHT10INTENSITY: " << LIGHT10INTENSITY;

    light10 = vtkSmartPointer<vtkLight>::New();
    if (ui->comboBox_29->currentText() == "on")
    {
        light10->SetFocalPoint(0, 0, 0);
        light10->SetPosition(LIGHT10POS1, LIGHT10POS2, LIGHT10POS3);
        light10->SetColor(LIGHT10COLOR1, LIGHT10COLOR2, LIGHT10COLOR3);
        light10->SetIntensity(LIGHT10INTENSITY);
    }


    // ENTIRE MAIN FROM ARROW
    //-------------------------------------------------------------------V
    vtkSmartPointer<vtkNamedColors> colors =
            vtkSmartPointer<vtkNamedColors>::New();

    // Create an arrow.
    vtkSmartPointer<vtkArrowSource> arrowSource =
            vtkSmartPointer<vtkArrowSource>::New();
    arrowSource->Update();

    // Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(arrowSource->GetOutputPort());
    vtkSmartPointer<vtkActor> actor =
            vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);


    // ADD ACTORS TO RENDERER
    //renderer->AddActor(actor);                    // arrow actor
    if (ui->comboBox_3->currentText() == "on")      // line actor
        renderer->AddActor(lineActor);

    if (ui->comboBox_5->currentText() == "on")      // volume actor
    {
        renderer->AddActor(volumeActor);
        renderer->AddActor(volumeOutlineActor);
    }
    if (ui->comboBox_7->currentText() == "on")      // surface actor
    {
        renderer->AddActor(surfaceActor);
        renderer->AddActor(surfaceActor2);
    }
    if (ui->comboBox_11->currentText() == "on")     // week5 actor
    {
        renderer->AddActor(cluster1Actor);
        renderer->AddActor(cluster2Actor);
        renderer->AddActor(planeActor);
        renderer->AddActor(objActor);
    }



    renderer->SetBackground(colors->GetColor3d("White").GetData());
    ui->openGLWidget->GetRenderWindow()->Render();
}


// FUNCTIONS START HERE
//=============================================================================================================V

// FOR LINE
//-------------------------------------------------------------------V
vtkSmartPointer<vtkActor> MainWindow::returnLineTubeActor(double LINE_radius, int LINE_numSides,
    double LINE_opacity)
{
    // Define some colors
    unsigned char red[3] = { 255, 0, 0 };
    unsigned char salmon[3] = { 255, 128, 144 };
    unsigned char orange[3] = { 255, 127, 0 };
    unsigned char yellow[3] = { 255, 255, 0 };
    unsigned char green[3] = { 0, 255, 0 };
    unsigned char blue[3] = { 0, 0, 255 };
    unsigned char darkmagenta[3] = { 139, 0, 139 };
    unsigned char violet[3] = { 139, 0, 255 };

    // Visualize (for background)
    colors = vtkSmartPointer<vtkNamedColors>::New();

    points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0.0, 0.0, 0.0);
    points->InsertNextPoint(1.0, 0.0, 0.0);
    points->InsertNextPoint(2.0, 1.0, 0.0);
    points->InsertNextPoint(2.0, 2.0, 0.0);
    points->InsertNextPoint(1.0, 3.0, 0.0);
    points->InsertNextPoint(0.0, 3.0, 0.0);
    points->InsertNextPoint(-1.0, 2.0, 0.0);
    points->InsertNextPoint(-1.0, 1.0, 0.0);

    // Create a polydata object and add everything to it
    polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);

    // note, line(s) is cell array, line is polyline
    lines = vtkSmartPointer<vtkCellArray>::New();	// cell array
    line = vtkSmartPointer<vtkPolyLine>::New();	// polyline

    line->GetPointIds()->SetNumberOfIds(8);
    line->GetPointIds()->SetId(0, 0);
    line->GetPointIds()->SetId(1, 1);
    line->GetPointIds()->SetId(2, 2);
    line->GetPointIds()->SetId(3, 3);
    line->GetPointIds()->SetId(4, 4);
    line->GetPointIds()->SetId(5, 5);
    line->GetPointIds()->SetId(6, 6);
    line->GetPointIds()->SetId(7, 7);

    lines->InsertNextCell(line);
    polyData->SetLines(lines);

    scalarValues = vtkSmartPointer<vtkDoubleArray>::New();
    scalarValues->SetNumberOfValues(8);
    scalarValues->SetValue(0, 1.0);
    scalarValues->SetValue(1, 2.0);
    scalarValues->SetValue(2, 3.0);
    scalarValues->SetValue(3, 4.0);
    scalarValues->SetValue(4, 5.0);
    scalarValues->SetValue(5, 6.0);
    scalarValues->SetValue(6, 7.0);
    scalarValues->SetValue(7, 8.0);

    // Setup the colors array
    colorsPolyTest = vtkSmartPointer<vtkUnsignedCharArray>::New();
    colorsPolyTest->SetNumberOfComponents(3);
    colorsPolyTest->SetName("Colors");

    // Add the three colors we have created to the array
    colorsPolyTest->InsertNextTupleValue(red);
    colorsPolyTest->InsertNextTupleValue(salmon);
    colorsPolyTest->InsertNextTupleValue(orange);
    colorsPolyTest->InsertNextTupleValue(yellow);
    colorsPolyTest->InsertNextTupleValue(green);
    colorsPolyTest->InsertNextTupleValue(blue);
    colorsPolyTest->InsertNextTupleValue(darkmagenta);
    colorsPolyTest->InsertNextTupleValue(violet);

    // Set scalar
    polyData->GetPointData()->SetScalars(colorsPolyTest);

    // Create a tube (cylinder) around the line
    tubePolyLineFilter = vtkSmartPointer<vtkTubeFilter>::New();
    tubePolyLineFilter->SetInputData(polyData);
    //tubePolyLineFilter->SetRadius(.1);	//default is .5
    tubePolyLineFilter->SetRadius(LINE_radius);	//default is .5
    //tubePolyLineFilter->SetNumberOfSides(12);
    tubePolyLineFilter->SetNumberOfSides(LINE_numSides);
    tubePolyLineFilter->SetCapping(true);
    tubePolyLineFilter->Update();

    // Create a mapper and actor
    tubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    tubeMapper->ScalarVisibilityOn();
    tubeMapper->SelectColorArray("Colors");
    tubeMapper->SetInputData(tubePolyLineFilter->GetOutput());

    tubeActor = vtkSmartPointer<vtkActor>::New();
    /*tubeActor->GetProperty()->SetOpacity(0.5); */
    tubeActor->GetProperty()->SetOpacity(LINE_opacity);
    tubeActor->SetMapper(tubeMapper);
    /*tubeActor->GetProperty()->SetSpecular(0.5);
    tubeActor->GetProperty()->SetDiffuse(0.5);
    tubeActor->GetProperty()->SetAmbient(0.5);*/

    return tubeActor;
}


// FOR VOLUME
//-------------------------------------------------------------------V
void MainWindow::volume_loadDataFromFile(const char* fileName)
{
    // Read,load the file
    reader = vtkSmartPointer<vtkStructuredPointsReader>::New();
    reader->SetFileName(fileName);
    reader->Update();
    volumeImageData = reader->GetOutput();
}

vtkSmartPointer<vtkProp> MainWindow::generateVolumeActor(double VOL_X1, double VOL_X2,
    double VOL_X3, double VOL_X4, double VOL_X5, double VOL_X6, double VOL_X7,
    double VOL_X8, double VOL_X9, double VOL_Y1, double VOL_Y2, double VOL_Y3,
    double VOL_Y4, double VOL_Y5, double VOL_Y6, double VOL_Y7, double VOL_Y8,
    double VOL_Y9)
{
    // You will need to use vtkSmartVolumeMapper to map the vtkImageData to the volume data.
    volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
    volumeMapper->SetBlendModeToComposite(); // composite first
    volumeMapper->SetInputData(volumeImageData);

    // use (1) vtkPiecewiseFunction to create a map for opacity and
    // (2) vtkColorTransferFunction to create the color map. These two mappings
    // are stored in the (3) vtkVolumeProperty
    // (3)
    volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
    volumeProperty->ShadeOff();
    volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);

    // The data range is from - 13.6758 to 13.7481; hence we can use opacity 1 for two
    // end values(-13.6758 and 13.7481), and 0 for the middle value which is 0.
    // (1)
    compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    //compositeOpacity->AddPoint(-13.6758, 1.0);
    //compositeOpacity->AddPoint(-9, 0.999);
    //compositeOpacity->AddPoint(-5, 0.999);
    //compositeOpacity->AddPoint(-1, 0.999);
    //compositeOpacity->AddPoint(0.0, 0.0);
    //compositeOpacity->AddPoint(1, 0.999);
    //compositeOpacity->AddPoint(5, 0.999);
    //compositeOpacity->AddPoint(9.0, 0.999);
    //compositeOpacity->AddPoint(13.7481, 0.999);

    compositeOpacity->AddPoint(VOL_X1, VOL_Y1);
    compositeOpacity->AddPoint(VOL_X2, VOL_Y2);
    compositeOpacity->AddPoint(VOL_X3, VOL_Y3);
    compositeOpacity->AddPoint(VOL_X4, VOL_Y4);
    compositeOpacity->AddPoint(VOL_X5, VOL_Y5);
    compositeOpacity->AddPoint(VOL_X6, VOL_Y6);
    compositeOpacity->AddPoint(VOL_X7, VOL_Y7);
    compositeOpacity->AddPoint(VOL_X8, VOL_Y8);
    compositeOpacity->AddPoint(VOL_X9, VOL_Y9);
    volumeProperty->SetScalarOpacity(compositeOpacity); // composite first.

    // For the color map, you can try to map - 13.6758 to the blue(0.0, 0.0, 1.0), 0 to
    // white(1.0, 1.0, 1.0) and 13.7481 to red(1.0, 0.0, 0.0).
    // (2)
    volumeColor = vtkSmartPointer<vtkColorTransferFunction>::New();
    volumeColor->AddRGBPoint(-13.6758, 0.0, 0.0, 1.0);
    volumeColor->AddRGBPoint(0.0, 1.0, 1.0, 1.0);
    volumeColor->AddRGBPoint(13.7482, 1.0, 0.0, 0.0);
    volumeProperty->SetColor(volumeColor);

    // The vtkVolume instance in the tutorial acts as an actor for volume rendering.
    // Thus, instead of adding an actor to the renderer, you will need to add
    // AddViewProp(vtkvolume)
    volumeVolume = vtkSmartPointer<vtkVolume>::New();
    volumeVolume->SetMapper(volumeMapper);
    volumeVolume->SetProperty(volumeProperty);

    return volumeVolume;
}

vtkSmartPointer<vtkActor> MainWindow::generateOutlineActor()
{
    volumeOutline = vtkSmartPointer<vtkOutlineFilter>::New();
    volumeOutline->SetInputData(volumeImageData);

    volumeOutlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    volumeOutlineMapper->SetInputConnection(volumeOutline->GetOutputPort());

    volumeOutlineActor = vtkSmartPointer<vtkActor>::New();
    volumeOutlineActor->SetMapper(volumeOutlineMapper);
    volumeOutlineActor->GetProperty()->SetColor(0, 0, 0);

    return volumeOutlineActor;
}


// FOR SURFACE
//-------------------------------------------------------------------V
// This function will load the vtkStructuredPoint data from a VTK file
void MainWindow::surface_loadDataFromFile(const char* fileName)
{
    surfaceReader = vtkSmartPointer<vtkStructuredPointsReader>::New();
    surfaceReader->SetFileName(fileName);
    surfaceReader->Update();
    myData = surfaceReader->GetOutput();
}

// This function will load myData and return an actor
vtkSmartPointer<vtkActor> MainWindow::generateIsoSurface(float threshold,
    double rr, double gg, double bb)
{
    mc = vtkSmartPointer<vtkMarchingCubes>::New();
    mc->SetInputData(myData);
    mc->ComputeNormalsOn();
    mc->ComputeGradientsOn();
    mc->SetValue(0., threshold);
    mc->Update();

    // To remain largest region
    confilter = vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
    confilter->SetInputConnection(mc->GetOutputPort());
    confilter->SetExtractionModeToLargestRegion();

    // Create a mapper
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(mc->GetOutputPort());
    mapper->ScalarVisibilityOff();    // utilize actor's property I set

    // Visualize
    actor = vtkSmartPointer<vtkActor>::New();
    actor->GetProperty()->SetColor(rr, gg, bb);
    //actor->GetProperty()->SetOpacity(0.5);
    actor->SetMapper(mapper);
    return actor;
}

// FOR WEEK5
//-------------------------------------------------------------------V
// CLUSTER1
//==================================================================
vtkSmartPointer<vtkActor> MainWindow::readAndReturnCluster1Actor(const char * fileName,
    double rr, double gg, double bb)
{
    // Get all data from the file
    vtkSmartPointer<vtkGenericDataObjectReader> reader =
        vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader->SetFileName(fileName);
    reader->Update();

    // All of the standard data types can be checked and obtained like this
    if (reader->IsFilePolyData())
    {
        cluster1Output = reader->GetPolyDataOutput();
        std::cout << "output is a polydata" << std::endl;
        std::cout << "output has " << cluster1Output->GetNumberOfPoints()
            << " points." << std::endl;
        std::cout << "output has " << cluster1Output->GetNumberOfLines()
            << " lines." << std::endl;

        /*mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputData(cluster1Output);

        cluster1Actor = vtkSmartPointer<vtkActor>::New();
        cluster1Actor->SetMapper(mapper);
        cluster1Actor->GetProperty()->SetColor(rr, gg, bb);
        cluster1Actor->GetProperty()->SetSpecular(1.0);
        cluster1Actor->GetProperty()->SetDiffuse(0.5);
        cluster1Actor->GetProperty()->SetAmbient(0.5);
        cluster1Actor->GetProperty()->SetOpacity(1.0);
        cluster1Actor->GetProperty()->SetSpecularColor(rr, gg, bb);*/

        // TUBE FILTER
        vtkSmartPointer<vtkTubeFilter> tubeFilter =
            vtkSmartPointer<vtkTubeFilter>::New();
        tubeFilter->SetInputConnection(reader->GetOutputPort());
        tubeFilter->SetRadius(.005); //default is .5
        tubeFilter->SetNumberOfSides(50);
        tubeFilter->SetCapping(true);
        tubeFilter->Update();

        // Create a mapper and actor
        vtkSmartPointer<vtkPolyDataMapper> tubeMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
        tubeMapper->SetInputConnection(tubeFilter->GetOutputPort());
        vtkSmartPointer<vtkActor> tubeActor =
            vtkSmartPointer<vtkActor>::New();
        //tubeActor->GetProperty()->SetOpacity(0.5);
        tubeActor->SetMapper(tubeMapper);
        tubeActor->GetProperty()->SetColor(rr, gg, bb);
        tubeActor->GetProperty()->SetSpecular(1.0);
        tubeActor->GetProperty()->SetDiffuse(0.0);
        tubeActor->GetProperty()->SetAmbient(0.5);
        tubeActor->GetProperty()->SetOpacity(1.0);
        tubeActor->GetProperty()->SetSpecularColor(rr, gg, bb);

        //return cluster1Actor;
        return tubeActor;
    }
}

// CLUSTER2
//==================================================================
vtkSmartPointer<vtkActor> MainWindow::readAndReturnCluster2Actor(const char * fileName,
    double rr, double gg, double bb)
{
    // Get all data from the file
    vtkSmartPointer<vtkGenericDataObjectReader> reader =
        vtkSmartPointer<vtkGenericDataObjectReader>::New();
    reader->SetFileName(fileName);
    reader->Update();

    // All of the standard data types can be checked and obtained like this
    if (reader->IsFilePolyData())
    {
        cluster2Output = reader->GetPolyDataOutput();
        std::cout << "output is a polydata" << std::endl;
        std::cout << "output has " << cluster2Output->GetNumberOfPoints()
            << " points." << std::endl;
        std::cout << "output has " << cluster2Output->GetNumberOfLines()
            << " lines." << std::endl;

        /*mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputData(cluster2Output);

        cluster2Actor = vtkSmartPointer<vtkActor>::New();
        cluster2Actor->SetMapper(mapper);
        cluster2Actor->GetProperty()->SetColor(rr, gg, bb);
        cluster2Actor->GetProperty()->SetSpecular(1.0);
        cluster2Actor->GetProperty()->SetDiffuse(0.0);
        cluster2Actor->GetProperty()->SetAmbient(0.5);
        cluster2Actor->GetProperty()->SetOpacity(1.0);
        cluster2Actor->GetProperty()->SetSpecularColor(rr, gg, bb);*/

        // TUBE FILTER
        vtkSmartPointer<vtkTubeFilter> tubeFilter =
            vtkSmartPointer<vtkTubeFilter>::New();
        tubeFilter->SetInputConnection(reader->GetOutputPort());
        tubeFilter->SetRadius(.005); //default is .5
        tubeFilter->SetNumberOfSides(50);
        tubeFilter->SetCapping(true);
        tubeFilter->Update();

        // Create a mapper and actor
        vtkSmartPointer<vtkPolyDataMapper> tubeMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
        tubeMapper->SetInputConnection(tubeFilter->GetOutputPort());
        vtkSmartPointer<vtkActor> tubeActor =
            vtkSmartPointer<vtkActor>::New();
        //tubeActor->GetProperty()->SetOpacity(0.5);
        tubeActor->SetMapper(tubeMapper);
        tubeActor->GetProperty()->SetColor(rr, gg, bb);
        tubeActor->GetProperty()->SetSpecular(1.0);
        tubeActor->GetProperty()->SetDiffuse(0.5);
        tubeActor->GetProperty()->SetAmbient(0.5);
        tubeActor->GetProperty()->SetOpacity(1.0);
        tubeActor->GetProperty()->SetSpecularColor(rr, gg, bb);

        //return cluster2Actor;
        return tubeActor;
    }
}

// PLANE
//==================================================================
vtkSmartPointer<vtkActor> MainWindow::readAndReturnPlaneActor(const char * fileName)
{
    // Get all data from the file
    vtkSmartPointer<vtkPolyDataReader> reader =
        vtkSmartPointer<vtkPolyDataReader>::New();
    reader->SetFileName(fileName);
    reader->Update();

    // All of the standard data types can be checked and obtained like this
    if (reader->IsFilePolyData())
    {
        vtkSmartPointer<vtkPolyData> polyData;
        vtkPolyData* planeOutput = reader->GetOutput();

        std::cout << "output is a polydata" << std::endl;
        std::cout << "output has " << planeOutput->GetNumberOfPoints()
            << " points." << std::endl;
        std::cout << "output has " << planeOutput->GetNumberOfLines()
            << " lines." << std::endl;

        mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputData(planeOutput);

        planeActor = vtkSmartPointer<vtkActor>::New();
        planeActor->SetMapper(mapper);
        //planeActor->GetProperty()->SetColor(rr, gg, bb);

        return planeActor;
    }
}

// OBJECT BOX, OBJ FILE
//==================================================================
vtkSmartPointer<vtkActor> MainWindow::generateOutlineActor(const char * fileName)
{
    vtkSmartPointer<vtkOBJReader> reader3 =
        vtkSmartPointer<vtkOBJReader>::New();
    reader3->SetFileName(fileName);
    reader3->Update();

    vtkSmartPointer<vtkPolyData> boundaryBox;
    boundaryBox = reader3->GetOutput();
    std::cout << "Number of points: " << boundaryBox->GetNumberOfPoints()
        << std::endl;

    // Create an outline filter for boundary box
    vtkSmartPointer<vtkOutlineFilter> objectOutline =
        vtkSmartPointer<vtkOutlineFilter>::New();
    objectOutline->SetInputData(boundaryBox);

    // Visualize
    vtkSmartPointer<vtkPolyDataMapper> mapper3 =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper3->SetInputConnection(objectOutline->GetOutputPort());

    vtkSmartPointer<vtkActor> actor3 =
        vtkSmartPointer<vtkActor>::New();
    actor3->SetMapper(mapper3);
    actor3->GetProperty()->SetColor(0, 0, 0);

    return actor3;
}


// FOR MAIN
//-------------------------------------------------------------------V
MainWindow::~MainWindow()
{
    delete ui;
}
