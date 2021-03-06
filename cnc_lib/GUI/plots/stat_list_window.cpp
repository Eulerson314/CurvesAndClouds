#include "stat_list_window.h"

void cnc::PlotFrame::mouseDoubleClickEvent(QMouseEvent *)
{
    StatListWindow* SLW = new StatListWindow(this);
    SLW->show();
}

cnc::StatListWindow::StatListWindow(PlotFrame* r) : QWidget(nullptr) , ref(r)
{
    QVBoxLayout* V = new QVBoxLayout;
    const uint NB_TYPES = stat_prop::types_name.size();

    auto in_types = r->list_types_contained();
    boxes.resize(NB_TYPES);

    for (uint j = 0;j<NB_TYPES;j++){
        if (in_types[j] && stat_prop::prop_names[j][0] != "null"){

            V->addWidget(new QLabel(QString::fromStdString(stat_prop::types_name[j])));

            boxes[j].resize(stat_prop::prop_names[j].size());

            for (uint k = 0;k<stat_prop::prop_names[j].size();k++){
                QCheckBox* CB = new QCheckBox(QString::fromStdString(stat_prop::prop_names[j][k]));
                V->addWidget(CB);
                boxes[j][k] = CB;
            }
        }
    }

    QPushButton* QB = new QPushButton("done");
    QObject::connect(QB,SIGNAL(clicked()),this,SLOT(exit_slot()));
    V->addWidget(QB);

    QWidget::setLayout(V);
}

void cnc::StatListWindow::exit_slot()
{
    StatList SL;
    SL.P.resize(boxes.size());
    for (uint j = 0;j<boxes.size();j++){
        SL.P[j].resize(boxes[j].size());
        for (uint i = 0;i<boxes[j].size();i++){
            SL.P[j][i] = boxes[j][i]->isChecked();
        }
    }
    StatWindow* S = new StatWindow(ref,SL);
    S->show();
    close();
}
