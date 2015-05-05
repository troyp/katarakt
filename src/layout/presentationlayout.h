#ifndef PRESENTATIONLAYOUT_H
#define PRESENTATIONLAYOUT_H

#include "layout.h"


class PresentationLayout : public Layout {
public:
	PresentationLayout(Viewer *v, int page = 0);
	PresentationLayout(Layout& old_layout);
	~PresentationLayout() {};

	bool supports_smooth_scrolling() const;
	const QRect calculate_placement(int page) const;
	void render(QPainter *painter);

	bool advance_hit(bool forward = true);
	bool advance_invisible_hit(bool forward = true);

	std::pair<int, QPointF> get_location_at(int px, int py);

	bool page_visible(int p) const;

private:
	int calculate_fit_width(int page) const;
	bool view_hit();
};

#endif

