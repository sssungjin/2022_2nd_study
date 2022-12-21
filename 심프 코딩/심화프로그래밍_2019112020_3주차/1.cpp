#include <iostream>
using namespace std;

class YoutubeSize {
private:
	int width;	//ResizeWindow 함수에서 따로 정의되지 않은 변수 width, height
	int height;	//를 사용했으므로 class의 private부분에 선언하였을 것이다.
public:
	YoutubeSize();
	YoutubeSize(int, int);
	int GetWidth();
	int GetHeight();
	void ResizeWindow(int, int);
};

YoutubeSize::YoutubeSize() : width(800), height(600) { }
YoutubeSize::YoutubeSize(int w, int h) : YoutubeSize() {	//int형 매개변수를 두개 받았고 함수 내부에서 w,h라는 변수를 사용하였으므로 
	ResizeWindow(w, h);	//int w, int h 를 매개변수로 받았을 것이다.
}

int YoutubeSize::GetHeight() {
	return height;	//정수형을 반환하는 함수이고 함수의 이름 또한 GetHeight 이므로 int형 height를 반환 할 것이다.
}
int YoutubeSize::GetWidth() {
	return width;	//정수형을 반환하는 함수이고 함수의 이름 또한 GetWidth 이므로 int형 width를 반환 할 것이다.
}

void YoutubeSize::ResizeWindow(int w, int h) {	//width와 height는 private에 선언되었고 변수 w,h는 선언이 안된 변수이므로 매개변수로 int w, int h 를 받았을 것이다.
	if (w > 800) width = w;
	else width = 800;

	if (h > 600) height = h;
	else height = 600;
}

int main() {
	YoutubeSize mainWindow;

	mainWindow.ResizeWindow(854, 480);	//ResizeWindow를 통해 height가 600보다 작으므로 600이 대입되었다.
	cout << mainWindow.GetWidth() << " x " << mainWindow.GetHeight() << '\n';	//GetWidth함수를 이용해 width, 즉 854를 반환 받아 출력하고 " x "를 출력한다. 그 후 GetHeight함수를 통해 위에서 600이 들어간 height를 출력한다.

	mainWindow.ResizeWindow(1920, 1080);	//각각 800, 600보다 크기 때문에 1920, 1080이 그대로 유지된다.
	cout << mainWindow.GetWidth() << " x " << mainWindow.GetHeight() << '\n';	//GetWidth함수를 이용해 width(1920)을 반환 받아 출력하고 " x "를 출력한다. 그 후 GetHeight함수를 통해 height, 즉 1080을 출력한다.

	mainWindow.ResizeWindow(3840, 2160);	//각각 800, 600보다 크기 때문에 3840, 2160이 그대로 유지된다.
	cout << mainWindow.GetWidth() << " x " << mainWindow.GetHeight() << '\n';	//GetWidth함수를 이용해 width(3840)을 반환 받아 출력하고 " x "를 출력한다. 그 후 GetHeight함수를 통해 height(2160)를 반환 받아 출력한다.

}