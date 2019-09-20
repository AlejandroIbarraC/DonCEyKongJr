package com.donkeykongjr.json;


import com.fasterxml.jackson.databind.ObjectMapper;
import org.json.JSONException;
import org.json.JSONObject;
import com.donkeykongjr.entity.*;
import java.io.*;

public class jsonParser {

    //Serialize a crocodile object to JSON format
    public static String serializeCocodrile(Cocodrile coco) throws IOException{

        ObjectMapper cocodrile_Mapper = new ObjectMapper();
        return cocodrile_Mapper.writeValueAsString(coco);

    }

    //Serialize a fruit object to JSON format
    public static String serializeFruit(Fruit fruit) throws IOException{

        ObjectMapper fruit_Mapper = new ObjectMapper();
        return fruit_Mapper.writeValueAsString(fruit);
    }

    public static void main(String[] args) {
        Cocodrile coco1 = new Cocodrile();
        coco1.iPos = 234;
        coco1.jPos = 567;
        coco1.cocoSpeed = 22;
        coco1.mouth = 2;
        coco1.onField = 99;
        coco1.onScreen = 1;
        coco1.onVine = 0;
        coco1.viewL = 12;
        coco1.viewR = 56;
        coco1.viewD = 8;
        coco1.viewU = 90;

        try {
            System.out.println(serializeCocodrile(coco1));
        }catch (IOException e){
            System.out.println("Error parseando el JSON");
        }

        Fruit fruit1 = new Fruit();
        try {
            System.out.println(serializeFruit(fruit1));
        }catch (IOException e){
            System.out.println("Error parseando el JSON");
        }
    }
}
