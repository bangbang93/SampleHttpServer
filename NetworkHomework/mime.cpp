#include "stdafx.h"
#include <string>
#include <map>
#include "mime.h"

using namespace std;

void init_mime()
{
	mime_map["shtml"] = "text/html";
	mime_map["htm"] = "text/html";
	mime_map["html"] = "text/html";
	mime_map["css"] = "text/css";
	mime_map["xml"] = "text/xml";
	mime_map["gif"] = "image/gif";
	mime_map["jpg"] = "image/jpeg";
	mime_map["jpeg"] = "image/jpeg";
	mime_map["js"] = "application/x-javascript";
	mime_map["atom"] = "application/atom+xml";
	mime_map["rss"] = "application/rss+xml";
	mime_map["mml"] = "text/mathml";
	mime_map["txt"] = "text/plain";
	mime_map["jad"] = "text/vnd.sun.j2me.app-descriptor";
	mime_map["wml"] = "text/vnd.wap.wml";
	mime_map["htc"] = "text/x-component";
	mime_map["png"] = "image/png";
	mime_map["tiff"] = "image/tiff";
	mime_map["tif"] = "image/tiff";
	mime_map["wbmp"] = "image/vnd.wap.wbmp";
	mime_map["ico"] = "image/x-icon";
	mime_map["jng"] = "image/x-jng";
	mime_map["bmp"] = "image/x-ms-bmp";
	mime_map["svgz"] = "image/svg+xml";
	mime_map["svg"] = "image/svg+xml";
	mime_map["webp"] = "image/webp";
	mime_map["ear"] = "application/java-archive";
	mime_map["war"] = "application/java-archive";
	mime_map["jar"] = "application/java-archive";
	mime_map["hqx"] = "application/mac-binhex40";
	mime_map["doc"] = "application/msword";
	mime_map["pdf"] = "application/pdf";
	mime_map["ai"] = "application/postscript";
	mime_map["eps"] = "application/postscript";
	mime_map["ps"] = "application/postscript";
	mime_map["rtf"] = "application/rtf";
	mime_map["xls"] = "application/vnd.ms-excel";
	mime_map["ppt"] = "application/vnd.ms-powerpoint";
	mime_map["wmlc"] = "application/vnd.wap.wmlc";
	mime_map["kml"] = "application/vnd.google-earth.kml+xml";
	mime_map["kmz"] = "application/vnd.google-earth.kmz";
	mime_map["7z"] = "application/x-7z-compressed";
	mime_map["cco"] = "application/x-cocoa";
	mime_map["jardiff"] = "application/x-java-archive-diff";
	mime_map["jnlp"] = "application/x-java-jnlp-file";
	mime_map["run"] = "application/x-makeself";
	mime_map["pm"] = "application/x-perl";
	mime_map["pl"] = "application/x-perl";
	mime_map["pdb"] = "application/x-pilot";
	mime_map["prc"] = "application/x-pilot";
	mime_map["rar"] = "application/x-rar-compressed";
	mime_map["rpm"] = "application/x-redhat-package-manager";
	mime_map["sea"] = "application/x-sea";
	mime_map["swf"] = "application/x-shockwave-flash";
	mime_map["sit"] = "application/x-stuffit";
	mime_map["tk"] = "application/x-tcl";
	mime_map["tcl"] = "application/x-tcl";
	mime_map["crt"] = "application/x-x509-ca-cert";
	mime_map["pem"] = "application/x-x509-ca-cert";
	mime_map["der"] = "application/x-x509-ca-cert";
	mime_map["xpi"] = "application/x-xpinstall";
	mime_map["xhtml"] = "application/xhtml+xml";
	mime_map["zip"] = "application/zip";
	mime_map["dll"] = "application/octet-stream";
	mime_map["exe"] = "application/octet-stream";
	mime_map["bin"] = "application/octet-stream";
	mime_map["deb"] = "application/octet-stream";
	mime_map["dmg"] = "application/octet-stream";
	mime_map["eot"] = "application/octet-stream";
	mime_map["img"] = "application/octet-stream";
	mime_map["iso"] = "application/octet-stream";
	mime_map["msm"] = "application/octet-stream";
	mime_map["msp"] = "application/octet-stream";
	mime_map["msi"] = "application/octet-stream";
	mime_map["kar"] = "audio/midi";
	mime_map["midi"] = "audio/midi";
	mime_map["mid"] = "audio/midi";
	mime_map["mp3"] = "audio/mpeg";
	mime_map["ogg"] = "audio/ogg";
	mime_map["m4a"] = "audio/x-m4a";
	mime_map["ra"] = "audio/x-realaudio";
	mime_map["3gp"] = "video/3gpp";
	mime_map["3gpp"] = "video/3gpp";
	mime_map["mp4"] = "video/mp4";
	mime_map["mpg"] = "video/mpeg";
	mime_map["mpeg"] = "video/mpeg";
	mime_map["mov"] = "video/quicktime";
	mime_map["webm"] = "video/webm";
	mime_map["flv"] = "video/x-flv";
	mime_map["m4v"] = "video/x-m4v";
	mime_map["mng"] = "video/x-mng";
	mime_map["asf"] = "video/x-ms-asf";
	mime_map["asx"] = "video/x-ms-asf";
	mime_map["wmv"] = "video/x-ms-wmv";
	mime_map["avi"] = "video/x-msvideo";

}

string get_mime(string fix)
{
	if (mime_map.count(fix) == 1)
	{
		return mime_map[fix];
	} else
	{
		return mime_map["html"];
	}
}