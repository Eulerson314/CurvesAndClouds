/**
  * @file plot_tab.h
  *
  *	defines Plot frame class
  */
#ifndef PLOT_TAB_H
#define PLOT_TAB_H
#if defined(CNC_LIB)
#  define CNC_LIB_EXPORT Q_DECL_EXPORT
#else
#  define CNC_LIB_EXPORT Q_DECL_IMPORT
#endif

#include "plot_frame.h"
#include "cnc_error.h"
#include "GUI/display_info.h"
#include <vector>
#include <QWidget>
#include <QGridLayout>
#include <QTimer>

namespace cnc {


/**
 * @brief The Plot_tab class defines a tab which contains plot frames
 */
class PlotTab : public QWidget
{
    Q_OBJECT;

public:
    /**
     * @brief Plot_tab initialize empty tab, displaying handled by QGridLayout
     * @param parent Qt parent to display and automatic destruction
     */
    PlotTab(QWidget* parent);

    /**
     * @brief add frame to a given location and size in frame grid throw error if place unavailable
     * @param px x position in grid
     * @param py y position in grid
     * @param w width number of cells of the frame
     * @param h height number of cells of the frame
     * @return reference to the created frame
     */
    PlotFrame* add_frame_at(int px,int py,int w = 1,int h = 1);


    /**
     * @brief add frame to the next available location
     * @param w width number of cells of the frame
     * @param h height number of cells of the frame
     * @return pointer to the created frame
     */
    PlotFrame* add_frame(int w = 1,int h = 1);

    float get_tab_ratio() const;

    ~PlotTab();

protected:
    void paintEvent(QPaintEvent*) override;
    void drawWidget(QPainter&);

private:
    float ratio;

    QGridLayout* Grid;

    std::vector<QRect> frame_grid;
    std::vector<PlotFrame*> frames;


    static constexpr int MAX_CELL_WIDTH = 10;
    static constexpr int MAX_CELL_HEIGHT = 8;
    static constexpr int CELL_SIZE = 100;

    PlotFrame* insert_frame(const QRect&);
};

}

#endif // PLOT_TAB_H
