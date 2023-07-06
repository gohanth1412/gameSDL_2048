#ifndef dohoa_h
#define dohoa_h


#include <iostream>
#include <SDL.h>
#include <vector>
using namespace  std;

/* dohoa_h */

    void logSDLError(std::ostream& os,
                    const std::string &msg, bool fatal = false);
    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int screenWidth, int screenHeight, const char* windowTitle);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    void waitUntilKeyPressed();
    //**************************************************************

    // Hàm nạp texture từ file ảnh, để vẽ lên renderer tương ứng
    SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

    // Hàm đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và giữ nguyên kích cỡ ban đầu của ảnh
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

    // Hàm (cùng trên nhưng khác tham số với hàm ngay trên)
    // đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và
    // với kích cỡ rộng (w) và cao (h) cho trước.
    // Ảnh sẽ được co dãn (phóng to thu nhỏ) cho khớp kích cỡ này.
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
#endif

