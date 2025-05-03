//
//  adapter.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/2.
//

#ifndef design_pattern_adapter_h
#define design_pattern_adapter_h

namespace adapter{

//像素格式
enum class PixelFormat{
    RGB = 0,
    YUV = 1,
};

//Image
struct Image{
    uint8_t *data {nullptr};
    int dataSize {0};
    PixelFormat format {PixelFormat::RGB};
    ~Image(){
        delete []data;
    }
};
//纯指针
////相机
//class Camera{
//public:
//    virtual ~Camera(){
//        
//    }
//public:
//    virtual Image* getImage() = 0;//输出YUV image
//};
//
//
////相机(仅支持输出YUV)
//class YUVCamera :public Camera{
//public:
//    Image* getImage() override{
//        Image* img = new Image();
//        img->format = format;
//        std::cout<<"yuv camera get image"<<std::endl;
//        return img;
//    }
//private:
//    PixelFormat format {PixelFormat::YUV};
//};
//
//
////相机(仅支持RGB格式输出)
//class RGBCamera :public Camera{
//public:
//    Image* getImage() override{
//        Image* img = new Image();
//        img->format = format;
//        std::cout<<"rgb camera get image"<<std::endl;
//        return img;
//    }
//private:
//    PixelFormat format {PixelFormat::RGB};
//};
//
//
////适配器
//class Adapter{
//public:
//    virtual ~Adapter(){
//        
//    }
//public:
//    virtual Image* convert(Image* src) = 0;
//};
//
//
////适配器
//class RGBAdapter:public Adapter{
//public:
//    Image* convert(Image* src) override{
//        Image* dst = new Image();
//        //data转换
//        //data size同步调整
//        dst->format = PixelFormat::YUV;
//        std::cout<<"RGBAdapter convert"<<std::endl;
//
//        return dst;
//    }
//};
//
//
////解析处理器
//class Parser{
//public:
//    Parser(Camera *camera){
//        this->camera = camera;
//    }
//public:
//    void setCamera(Camera* camera){
//        this->camera = camera;
//    }
//    void setAdapter(Adapter* adapter){
//        this->adapter = adapter;
//    }
//    Image* getImage(){
//        if(camera == nullptr){
//            return nullptr;
//        }
//        Image* img = camera->getImage();
//        if(img->format != PixelFormat::YUV){
//            if(adapter != nullptr){
//                Image* dst = adapter->convert(img);
//                return dst;
//            }
//            delete img;
//            return nullptr;
//        }
//        return img;
//    }
//private:
//    Camera* camera{nullptr};
//    Adapter* adapter{nullptr};
//};

//unique_ptr
//相机
class Camera{
public:
    virtual ~Camera(){
        
    }
public:
    virtual std::unique_ptr<Image> getImage() = 0;//输出YUV image
};


//相机(仅支持输出YUV)
class YUVCamera :public Camera{
public:
    std::unique_ptr<Image>  getImage() override{
        auto img = std::make_unique<Image>();
        img->format = format;
        std::cout<<"yuv camera get image"<<std::endl;
        return img;
    }
private:
    PixelFormat format {PixelFormat::YUV};
};


//相机(仅支持RGB格式输出)
class RGBCamera :public Camera{
public:
    std::unique_ptr<Image> getImage() override{
        auto img = std::make_unique<Image>();
        img->format = format;
        std::cout<<"rgb camera get image"<<std::endl;
        return img;
    }
private:
    PixelFormat format {PixelFormat::RGB};
};


//适配器
class Adapter{
public:
    virtual ~Adapter(){
        
    }
public:
    virtual std::unique_ptr<Image> convert(std::unique_ptr<Image>& src) = 0;
};


//适配器
class RGBAdapter:public Adapter{
public:
    std::unique_ptr<Image> convert(std::unique_ptr<Image>& src) override{
//        std::unique_ptr<Image> dst = std::make_unique<Image>();
        auto dst = std::make_unique<Image>();

        //data转换
        //data size同步调整
        dst->format = PixelFormat::YUV;
        std::cout<<"RGBAdapter convert"<<std::endl;

        return dst;
    }
};


//解析处理器
class Parser{
public:
    Parser(std::unique_ptr<Camera> camera){
        this->camera = std::move(camera);
    }
public:
    void setCamera(std::unique_ptr<Camera> camera){
        this->camera = std::move(camera);
    }
    void setAdapter(std::unique_ptr<Adapter> adapter){
        this->adapter = std::move(adapter);
    }
    std::unique_ptr<Image> getImage(){
        if(camera == nullptr){
            return nullptr;
        }
        auto img = camera->getImage();
        if(img->format != PixelFormat::YUV){
            if(adapter != nullptr){
                //std::unique_ptr<Image> dst = std::move(adapter->convert(img));
                auto dst = adapter->convert(img);

                return dst;
            }
            return nullptr;
        }
        return img;
    }
private:
    std::unique_ptr<Camera> camera{nullptr};
    std::unique_ptr<Adapter> adapter{nullptr};
};

}




#endif /* adapter_h */
