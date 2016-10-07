#include <schead.h>
#include <scjson.h>

// 测试 cjson 函数
void test_readstr(void) {
	// 第二个 测试 json 串的解析
	puts("测试 cjson 是否可用");
	char text1[] = "{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";
	TSTR_NEW(jstr1);
	jstr1->str = text1;
	cjson_t js = cjson_newtstr(jstr1);

	cjson_t name = cjson_getobject(js, "name");
	printf("name => %s\n", name->vs);

	cjson_t format = cjson_getobject(js, "format");
	printf("len(format) => %d\n", cjson_getlen(format));

	cjson_t interlace = cjson_getobject(format, "interlace");
	printf("interlace => %d\n", cjson_getint(interlace));

	cjson_delete(js);

	//进行第三组测试

	puts(" 测试 数组的读取");
	char text2[] = "[\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"]";
	TSTR_NEW(jstr2);
	jstr2->str = text2;
	js = cjson_newtstr(jstr2);
	int len = cjson_getlen(js);
	int i;
	for (i = 0; i < len; ++i) {
		cjson_t item = cjson_getarray(js,i);
		printf("%d => %s.\n", i, item->vs);
	}
	cjson_delete(js);


	puts("第三组测试");
	char text3[] = "[\n    [0, -1, 0],\n    [1, 0, 0],\n    [0, 0, 1]\n	]\n";
	TSTR_NEW(jstr3);
	jstr3->str = text3;
	js = cjson_newtstr(jstr3);
	len = cjson_getlen(js);
	for (i = 0; i < len; ++i) {
		cjson_t item = cjson_getarray(js, i);
		printf("%d => %d.\n", i, cjson_getlen(item));
	}

	cjson_delete(js);
}

/*
 * simple c 框架业务层启动的代码
 */
void test_readfile(void) {

	// 测试json解析结果是否正常
	char * path = "./main/config/goods.json";
	cjson_t goods = cjson_newfile(path);

	// 数据输出
	int len = cjson_getlen(goods);
	printf("len = %d\n", len);

	// 打印其中一个数据
	int idx = len / 2;
	cjson_t jsidx = cjson_getarray(goods, idx);
	int ilen = cjson_getlen(jsidx);
	printf("ilen = %d\n", ilen);
	printf("[\"%s\", \"%s\", %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n",
		cjson_getarray(jsidx, 0)->vs, 
		cjson_getarray(jsidx, 1)->vs,
		cjson_getint(cjson_getarray(jsidx, 2)),
		cjson_getint(cjson_getarray(jsidx, 3)),
		cjson_getint(cjson_getarray(jsidx, 4)),
		cjson_getint(cjson_getarray(jsidx, 5)),
		cjson_getint(cjson_getarray(jsidx, 6)),
		cjson_getint(cjson_getarray(jsidx, 7)),
		cjson_getint(cjson_getarray(jsidx, 8)),
		cjson_getint(cjson_getarray(jsidx, 9)),
		cjson_getint(cjson_getarray(jsidx, 10)),
		cjson_getint(cjson_getarray(jsidx, 11)),
		cjson_getint(cjson_getarray(jsidx, 12)),
		cjson_getint(cjson_getarray(jsidx, 13)),
		cjson_getint(cjson_getarray(jsidx, 14)),
		cjson_getint(cjson_getarray(jsidx, 15))
	);

	cjson_delete(goods);
}