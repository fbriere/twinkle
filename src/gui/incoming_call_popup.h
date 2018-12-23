#ifndef T_INCOMING_CALL_POPUP_H
#define T_INCOMING_CALL_POPUP_H

#include <QQuickItem>
#include <QQuickView>
#include <QImage>

class IncomingCallImageProvider;

class IncomingCallPopup : public QObject
{
	Q_OBJECT
public:
	explicit IncomingCallPopup(QObject *parent = 0);
	virtual ~IncomingCallPopup();

	void setCallerName(const QString& name);
	void setCallerPhoto(const QImage& photo);
	void show();
	void hide();
	void setVisible(bool v) { if (v) show(); else hide(); }
    void move(int x, int y);

private:
	void positionWindow();
signals:
	void answerClicked();
	void rejectClicked();
public slots:
	void onAnswerClicked();
	void onRejectClicked();
	void saveState();
private:
	QQuickView* m_view;
	QQuickItem* m_callerText;
	IncomingCallImageProvider* m_imageProvider;
};

#endif // T_INCOMING_CALL_POPUP_H
