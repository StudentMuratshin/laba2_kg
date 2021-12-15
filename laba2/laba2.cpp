#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "cr.cpp"
using namespace sf;
using namespace std;

class Circle : public CircleShape
{
public:
    Circle(int R, int G, int B, float x, float y, int r)
    {
        R = R; G = G; B = B;
        this->setFillColor(Color(R, G, B));
        this->setRadius(r);
        this->setPosition(x, y);
        this->setOrigin(r, r);
    }
};
vector<Vector2f> points(vector<Vector2f> xy)
{
    vector<Vector2f> points_xy;
    for (float t = 0; t <= 1.05; t+=0.05)
    {
        points_xy.push_back(xy[0] * (powf(1 - t, 3)) + 3.f * xy[1] * (powf(1 - t, 2)) * t + 3.f * xy[2] * (1 - t) * powf(t, 2) + xy[3] * powf(t,3));
    }
    return points_xy;
}

int main()
{
    int fps = 30;
	
	vector <Vector2f> top_img
	{
		Vector2f(573,1012),
		Vector2f(573, 1000),
		Vector2f(575, 986),
		Vector2f(579, 970),
		Vector2f(581, 960),
		Vector2f(586, 947),
		Vector2f(591, 934),
		Vector2f(596, 927),
		Vector2f(602, 919),
		Vector2f(610, 907),
		Vector2f(615, 899),
		Vector2f(621, 889),
		Vector2f(625, 880),
		Vector2f(631, 872),
		Vector2f(634, 866),
		Vector2f(638 ,861),
		Vector2f(642, 854),
		Vector2f(648, 850),
		Vector2f(659, 848),
		Vector2f(667, 845),
		Vector2f(672, 843),
		Vector2f(675, 843),
		Vector2f(685, 838),
		Vector2f(693, 835),
		Vector2f(697 ,827),
		Vector2f(701 ,817),
		Vector2f(705, 808),
		Vector2f(708, 799),
		Vector2f(711 ,794),
		Vector2f(715 ,786),
		Vector2f(721, 781),
		Vector2f(726, 771),
		Vector2f(733 ,765),
		Vector2f(745, 757),
		Vector2f(746, 744),
		Vector2f(748, 727),
		Vector2f(749, 716),
		Vector2f(751, 705),
		Vector2f(752, 695),
		Vector2f(754, 682),
		Vector2f(752, 670),
		Vector2f(745, 655),
		Vector2f(740, 641),
		Vector2f(735, 622),
		Vector2f(731, 602),
		Vector2f(728, 585),
		Vector2f(727, 566),
		Vector2f(729, 552),
		Vector2f(729, 537),
		Vector2f(733,525),
		Vector2f(732, 522),
		Vector2f(738 ,506),
		Vector2f(744, 492),
		Vector2f(744, 478),
		Vector2f(745, 454),
		Vector2f(744, 434),
		Vector2f(747 ,419),
		Vector2f(750, 403),
		Vector2f(749, 379),
		Vector2f(748, 359),
		Vector2f(752, 340),
		Vector2f(755, 321),
		Vector2f(762, 302),
		Vector2f(769, 283),
		Vector2f(781, 260),
		Vector2f(793 ,245),
		Vector2f(806, 233),
		Vector2f(814,221),
		Vector2f(832 ,230),
		Vector2f(841, 241),
		Vector2f(850 ,261),
		Vector2f(862, 277),
		Vector2f(869, 290),
		Vector2f(876, 307),
		Vector2f(873, 306),
		Vector2f(877 ,318),
		Vector2f(883 ,332),
		Vector2f(887, 349),
		Vector2f(900 ,353),
		Vector2f(927, 349),
		Vector2f(950, 351),
		Vector2f(985, 352),
		Vector2f(1023, 357),
		Vector2f(1055, 363),
		Vector2f(1074, 363),
		Vector2f(1092, 344),
		Vector2f(1102, 328),
		Vector2f(1119 ,306),
		Vector2f(1134, 286),
		Vector2f(1149 ,273),
		Vector2f(1167, 265),
		Vector2f(1181, 288),
		Vector2f(1184, 316),
		Vector2f(1186, 350),
		Vector2f(1185, 351),
		Vector2f(1187 ,375),
		Vector2f(1186, 395),
		Vector2f(1186, 421),
		Vector2f(1179, 450),
		Vector2f(1180, 466),
		Vector2f(1182, 495),
		Vector2f(1182, 513),
		Vector2f(1184, 530),
		Vector2f(1189, 555),
		Vector2f(1200, 587),
		Vector2f(1197, 614),
		Vector2f(1189, 638),
		Vector2f(1180, 660),
		Vector2f(1166, 683),
		Vector2f(1150, 707),
		Vector2f(1132, 726),
		Vector2f(1120, 736),
		Vector2f(1113, 738),
		Vector2f(1103, 751),
		Vector2f(1094, 771),
		Vector2f(1101, 796),
		Vector2f(1110, 815),
		Vector2f(1125, 853),
		Vector2f(1116, 835),
		Vector2f(1131, 880),
		Vector2f(1134, 902),
		Vector2f(1145, 920),
		Vector2f(1159 ,941),
		Vector2f(1170, 964),
		Vector2f(1180, 986),
		Vector2f(1178, 1007),
		Vector2f(1151, 1011),
		Vector2f(1123, 1012),
		Vector2f(1113, 1010),
		Vector2f(1089 ,1012),
		Vector2f(1040, 1012),
		Vector2f(992, 1014),
		Vector2f(953, 1011),
		Vector2f(921, 1012),
		Vector2f(883, 1013),
		Vector2f(840, 1014),
		Vector2f(803, 1014),
		Vector2f(775, 1014),
		Vector2f(745, 1014),
		Vector2f(718, 1013),
		Vector2f(672, 1013),
		Vector2f(644, 1013),
		Vector2f(619, 1013),
		Vector2f(598, 1013), 
		Vector2f(576, 1013),
		Vector2f(575, 1006)
	};
    vector <Vector2f> point_xyy;
    vector <Circle> tops;
    //vector <Vector2f> top_img;
	vector <Vector2f> xxx;
    RenderWindow window(VideoMode(), "kg2", Style::Fullscreen);
    window.setFramerateLimit(fps);
    while (window.isOpen())
    {
		int k = 0;
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			for (int i = 1; i < top_img.size()-1; i=i+3)
			{

				if (i % 2 == 0)
					top_img.erase(top_img.begin() + i);

			}
		}
        
        Event event;
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();

            if (event.type == Event::Closed)
                window.close();
        }
        Vector2i position = Mouse::getPosition();

        static bool lock_click;
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left && lock_click != true)
            {
                point_xyy.push_back(Vector2f(position.x, position.y));
                tops.push_back(Circle(250, 250, 0, position.x, position.y, 3));
                lock_click = true;
            }
        }
        if (event.type == Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                lock_click = false;
            }
        }
        
        window.clear(Color::Black);
        VertexArray lines_1(LinesStrip, 2);
        for (int i = 0; i < top_img.size(); i++)
        {
			if (k > top_img.size())
				break;
            for (int j = 0; j < 4; j++)
            {
				if (k < top_img.size())
					xxx.push_back(top_img[k]);
                
				//cout << top_img[k].x << ' ' << top_img[k].y << endl;
                k++;
            }
			if (xxx.size() == 4)
			{
				for (int j = 0; j < points(xxx).size() - 1; ++j)
				{
					lines_1[0].position = Vector2f(points(xxx)[j]);
					lines_1[1].position = Vector2f(points(xxx)[j + 1]);
					lines_1[0].color = Color::Blue;
					lines_1[1].color = Color::Cyan;
					window.draw(lines_1);
				}
			}
			k--;
            xxx.clear();
		}

        
        
        if (point_xyy.size() == 4)
        {
            for (int i = 0; i < points(point_xyy).size() - 1; ++i)
            {
                lines_1[0].position = Vector2f(points(point_xyy)[i]);
                lines_1[1].position = Vector2f(points(point_xyy)[i + 1]);
                tops.push_back(Circle(250, 250, 0, points(point_xyy)[i].x, points(point_xyy)[i].y, 3));
                lines_1[0].color = Color::Blue;
                lines_1[1].color = Color::Cyan;
                window.draw(lines_1);
            }
           // point_xy.clear();
        }

        for (auto& s : tops)
        {
            window.draw(s);
        }
        window.display();
    }
    
    return 0;
}